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
DMG_DIR_PATH="${MESON_BUILD_ROOT}/Conjugateur v${1}"
DMG_PATH="${DIST_PATH}/Conjugateur v${1}.dmg"
BUNDLE_PATH="${MESON_BUILD_ROOT}/Conjugateur.app"

# Rebundle the app if it doesn't exist yet.
if [ -d ${BUNDLE_PATH} ]; then
        echo "dmg_mac: bundle \"Conjugateur.app\" exists, not rebundling"
else
        echo "dmg_mac: rebundling \"Conjugateur.app\""
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


# Build a DMG from the bundle.
mkdir -p "${DMG_DIR_PATH}"
ditto "${BUNDLE_PATH}" "${DMG_DIR_PATH}/Conjugateur.app"

hdiutil create -srcFolder "${DMG_DIR_PATH}" -o "${DMG_PATH}"

# Build the final installer package, and sign it if codesigning is enabled.
if [ ${CODESIGN} ]; then
    codesign -s "${CERT_APPL}" --timestamp -i "ch.tifrueh.conjugateur" "${DMG_PATH}"
fi
