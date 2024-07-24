#!/bin/sh

# Change to the meson source root directory.
cd "${MESON_SOURCE_ROOT}"

# Echo help message if no argument is given.
if [ ! ${1} ]; then
	echo "Usage: dmg_mac.sh [VERSION NUMBER]"
	exit
fi

echo "dmg_mac: building DMG"

# Define default certificates to sign with.
CERT_APPL=${CERT_APPL:-"Application"}

# Echo additional debugging info about codesigning.
if [ ${CODESIGN} ]; then
        echo "dmg_mac: enabling codesigning"
        echo "dmg_mac: using Depeloper ID Application Certificate \"${CERT_APPL}\""

else
        echo "dmg_mac: disabling codesigning"
fi

# Define various useful path variables.
DIST_PATH="${MESON_SOURCE_ROOT}/dist/macOS"
DMG_DIR_PATH="${MESON_BUILD_ROOT}/Conjugator v${1}"
DMG_PATH="${DIST_PATH}/Conjugator-macOS-universal-v${1}.dmg"
BUNDLE_PATH="${MESON_BUILD_ROOT}/Conjugator.app"

# Bundle the app.
echo "dmg_mac: Bundling \"Conjugator.app\""
/bin/sh "${MESON_SOURCE_ROOT}/scripts/bundle_mac.sh"

# Sign the bundle if codesigning is enabled.
if [ ${CODESIGN} ]; then
        codesign --sign "${CERT_APPL}" \
                --options "runtime" \
                --bundle-version "${1}" \
                --force --timestamp \
                "${BUNDLE_PATH}"
fi


# Build a DMG from the bundle.
mkdir -p "${DMG_DIR_PATH}"
ditto "${BUNDLE_PATH}" "${DMG_DIR_PATH}/Conjugator.app"

hdiutil create -srcFolder "${DMG_DIR_PATH}" -o "${DMG_PATH}"

# Build the final installer package, and sign it if codesigning is enabled.
if [ ${CODESIGN} ]; then
    codesign -s "${CERT_APPL}" --timestamp -i "ch.tifrueh.conjugator" "${DMG_PATH}"
fi
