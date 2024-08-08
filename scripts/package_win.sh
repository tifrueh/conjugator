#!/bin/sh

# Change to the meson build directory.
cd ${MESON_BUILD_ROOT}

# Define various useful path variables.
MESON_RES_PATH="${MESON_SOURCE_ROOT}/resources"
MESON_LC_FR_PATH="${MESON_BUILD_ROOT}/po/fr/LC_MESSAGES"
MESON_LC_DE_PATH="${MESON_BUILD_ROOT}/po/de/LC_MESSAGES"

echo "package_win: compiling wxstd catalogues"

# Compile the wxstd catalogues and put them to the location expected by the
# inno setup script.
mkdir -p ${MESON_BUILD_ROOT}/wxstd/fr
mkdir -p ${MESON_BUILD_ROOT}/wxstd/de

msgfmt -o ${MESON_BUILD_ROOT}/wxstd/fr/wxstd.mo ${MESON_RES_PATH}/wxstd/fr.po
msgfmt -o ${MESON_BUILD_ROOT}/wxstd/de/wxstd.mo ${MESON_RES_PATH}/wxstd/de.po

echo "package_win: starting inno setup compiler"

# Invoke the inno setup compiler.
iscc ${MESON_BUILD_ROOT}/configuration-files/conjugator.iss
