#!/bin/sh

cd "${MESON_SOURCE_ROOT}"

if [ ! ${1} ]; then
	echo "Usage: package_mac.sh [VERSION NUMBER]"
	exit
fi

echo "package_mac: packaging Conjugateur version ${1}"

CERT_PKG=${CERT_PKG:-"Installer"}
CERT_APPL=${CERT_APPL:-"Application"}
MACOSX_DEPLOYMENT_TARGET=${MACOSX_DEPLOYMENT_TARGET:-"11"}

echo "package_mac: setting minimum macOS version to \"${MACOSX_DEPLOYMENT_TARGET}\""

if [ ${CODESIGN} ]; then
	echo "package_mac: enabling codesigning"
	echo "package_mac: using Developer ID Installer Certificate \"${CERT_PKG}\""
	echo "package_mac: using Depeloper ID Application Certificate \"${CERT_APPL}\""

else
	echo "package_mac: disabling codesigning"
fi

DIST_PATH="${MESON_SOURCE_ROOT}/dist/macOS"
COMPONENT_PKG_PATH="${DIST_PATH}/Conjugateur-macOS-universal-v${1}.component.pkg"
DISTFILE_PATH="${DIST_PATH}/distfile.plist"
PKG_PATH="${DIST_PATH}/Conjugateur-macOS-universal-v${1}.pkg"
BUNDLE_PATH="${MESON_BUILD_ROOT}/Conjugateur.app"

if [ -d ${BUNDLE_PATH} ]; then
	echo "package_mac: bundle \"Conjugateur.app\" exists, not rebundling"
else
	echo "package_mac: rebundling \"Conjugateur.app\""
	/bin/sh "${MESON_SOURCE_ROOT}/scripts/bundle_mac.sh"
fi

if [ ${CODESIGN} ]; then
	codesign --sign "${CERT_APPL}" \
		--options "runtime" \
		--bundle-version "${1}" \
		--force --timestamp \
		"${BUNDLE_PATH}"
fi


pkgbuild --component "${BUNDLE_PATH}"\
	--identifier "ch.tifrueh.conjugateur" \
	--version "${1}" \
	--install-location "/Applications" \
	--compression "latest" \
	--min-os-version "${MACOSX_DEPLOYMENT_TARGET}" \
	"${COMPONENT_PKG_PATH}"

productbuild --synthesize \
	--package "${COMPONENT_PKG_PATH}" \
	"${DISTFILE_PATH}"

awk -v MSRT=${MESON_SOURCE_ROOT} '
/<\/installer-gui-script>/ {
   print "    <license file=\""MSRT"/resources/LICENSE.html\"\/>"
}
{ print }
' ${DISTFILE_PATH} > "${DISTFILE_PATH}.new"

mv -f "${DISTFILE_PATH}.new" "${DISTFILE_PATH}"

if [ ${CODESIGN} ]; then
	productbuild --distribution "${DISTFILE_PATH}" \
		--package-path "${DIST_PATH}" \
		--sign "${CERT_PKG}" \
		"${PKG_PATH}"
else
	productbuild --distribution "${DISTFILE_PATH}" \
		--package-path "${DIST_PATH}" \
		"${PKG_PATH}"
fi

rm -r "${DISTFILE_PATH}" "${BUNDLE_PATH}" "${COMPONENT_PKG_PATH}"
