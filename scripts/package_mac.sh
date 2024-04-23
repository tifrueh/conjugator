#!/bin/sh

# Change to the meson source root directory.
cd "${MESON_SOURCE_ROOT}"

# Echo help message if no argument is given.
if [ ! ${1} ]; then
	echo "Usage: package_mac.sh [VERSION NUMBER]"
	exit
fi

echo "package_mac: packaging Conjugateur version ${1}"

# Define default certificates to sign with.
CERT_PKG=${CERT_PKG:-"Installer"}
CERT_APPL=${CERT_APPL:-"Application"}
MACOSX_DEPLOYMENT_TARGET=${MACOSX_DEPLOYMENT_TARGET:-"11"}

echo "package_mac: setting minimum macOS version to \"${MACOSX_DEPLOYMENT_TARGET}\""

# Echo additional debugging info about codesigning.
if [ ${CODESIGN} ]; then
	echo "package_mac: enabling codesigning"
	echo "package_mac: using Developer ID Installer Certificate \"${CERT_PKG}\""
	echo "package_mac: using Depeloper ID Application Certificate \"${CERT_APPL}\""

else
	echo "package_mac: disabling codesigning"
fi

# Define various useful path variables.
DIST_PATH="${MESON_SOURCE_ROOT}/dist/macOS"
COMPONENT_PKG_PATH="${DIST_PATH}/Conjugateur-macOS-universal-v${1}.component.pkg"
DISTFILE_PATH="${DIST_PATH}/distfile.plist"
PKG_PATH="${DIST_PATH}/Conjugateur-macOS-universal-v${1}.pkg"
BUNDLE_PATH="${MESON_BUILD_ROOT}/Conjugateur.app"

# Rebundle the app if it doesn't exist yet.
if [ -d ${BUNDLE_PATH} ]; then
	echo "package_mac: bundle \"Conjugateur.app\" exists, not rebundling"
else
	echo "package_mac: rebundling \"Conjugateur.app\""
	/bin/sh "${MESON_SOURCE_ROOT}/scripts/bundle_mac.sh"
fi

# Sign the bundle if codesigning is enabled.
if [ ${CODESIGN} ]; then
	codesign --sign "${CERT_APPL}" \
		--options "runtime" \
		--bundle-version "${1}" \
		--force --timestamp \
		"${BUNDLE_PATH}"
fi


# Build a component package from the bundle.
pkgbuild --component "${BUNDLE_PATH}"\
	--identifier "ch.tifrueh.conjugateur" \
	--version "${1}" \
	--install-location "/Applications" \
	--compression "latest" \
	--min-os-version "${MACOSX_DEPLOYMENT_TARGET}" \
	"${COMPONENT_PKG_PATH}"

# Synthesise a distfile from the component package.
productbuild --synthesize \
	--package "${COMPONENT_PKG_PATH}" "/Applications" \
	"${DISTFILE_PATH}"

# Insert a line defining the license file into the distfile with awk.
awk -v MSRT=${MESON_SOURCE_ROOT} '
/<\/installer-gui-script>/ {
   print "    <license file=\""MSRT"/resources/LICENSE.html\"\/>"
}
{ print }
' ${DISTFILE_PATH} > "${DISTFILE_PATH}.new"

mv -f "${DISTFILE_PATH}.new" "${DISTFILE_PATH}"

# Build the final installer package, and sign it if codesigning is enabled.
if [ ${CODESIGN} ]; then
	productbuild --distribution "${DISTFILE_PATH}" \
		--package-path "${DIST_PATH}" \
		--sign "${CERT_PKG}" \
		--version "${1}" \
		"${PKG_PATH}"
else
	productbuild --distribution "${DISTFILE_PATH}" \
		--package-path "${DIST_PATH}" \
		--version "${1}" \
		"${PKG_PATH}"
fi

# Remove the distfile, the bundle and the component package. This is necessary
# as the installer may install the app to the place where it finds another
# version of it, e. g. build/Conjugateur.app, which is, of course, not exactly
# desirable.
rm -r "${DISTFILE_PATH}" "${BUNDLE_PATH}" "${COMPONENT_PKG_PATH}"
