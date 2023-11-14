#!/bin/sh

cd "${MESON_SOURCE_ROOT}"

if [ ! ${1} ]; then
	echo "Usage: package_mac.sh [VERSION NUMBER]"
	exit
fi

CERT_PKG=${CERT_PKG:-"Installer"}
CERT_APPL=${CERT_APPL:-"Application"}
MIN_MACOS=${MIN_MACOS:-"14"}

echo "package_mac: use Developer ID Installer Certificate \"${CERT_PKG}\""
echo "package_mac: use Depeloper ID Application Certificate \"${CERT_APPL}\""
echo "package_mac: set minimum macOS version to \"${MIN_MACOS}\""

if [ ${CODESIGN} ]; then
	echo "package_mac: enable codesigning"
else
	echo "package_mac: disable codesigning"
fi

DIST_PATH="${MESON_SOURCE_ROOT}/dist/macOS"
COMPONENT_PKG_PATH="${DIST_PATH}/Conjugateur-macOS-${MIN_MACOS}-universal-v${1}.component.pkg"
DISTFILE_PATH="${DIST_PATH}/distfile.plist"
PKG_PATH="${DIST_PATH}/Conjugateur-macOS-${MIN_MACOS}-universal-v${1}.pkg"
BUNDLE_PATH="${MESON_BUILD_ROOT}/Conjugateur.app"

if [ -d ${BUNDLE_PATH} ]; then
	echo "package_mac: bundle \"Conjugateur.app\" exists, will not bundle again"
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
	--min-os-version "${MIN_MACOS}" \
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
