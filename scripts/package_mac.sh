#!/bin/sh

# USAGE ========================================================================
#
# package_mac.sh – Package a macOS bundle for release.
#
# environment:
#
#   CERT_APPL                   The name of the developer certificate to use
#                               for signing applications.
#   CERT_PKG                    The name of the developer certificate to use
#                               for signing installers.
#   NOCODESIGN                  Set (to anything) to disable codesigning.
#   NOTARIZE_KC                 The keychain with which to perform
#                               notarisation.
#   NONOTARIZE                  Set (to anything) to disable notarisation.
#   DTARGET                     The minimum macOS version to support.

PROG=$0

HELP="usage: ${PROG} VERSION BUNDLE LICENSE OUTDIR

arguments:

    VERSION     The version string to embed. Must be of the form
                [0-9]+\\.[0-9]+\\.[0-9]+
    BUNDLE      The relative path to the bundle to be packaged.
    LICENSE     The relative path to the license to bundle with the package.
    OUTDIR      The relative path to the directory in which to place the
                package.
"

# ==============================================================================

# LOGGING ======================================================================

info () {
    printf "%s: info: %s\n" "${PROG}" "${1}"
}

error () {
    printf "%s: error: %s\n" "${PROG}" "${1}" 1>&2
}

# ==============================================================================

# Echo help message if argument count doesn't match.
if [ $# -ne 4 ]; then
    printf "%s" "${HELP}"
    exit 1
fi

# Extract arguments.
if echo "${1}" | grep -E '^[0-9]+\.[0-9]+\.[0-9]+$' > /dev/null; then
    VERSION="${1}"
else
    error "Incorrect VERSION format"
    exit 1
fi

if [ ! -d "${2}" ]; then
    error "${2} does not exist or is no directory"
    exit 1
fi

if [ ! -f "${3}" ]; then
    error "${3} does not exist or is no regular file"
    exit 1
fi

if [ ! -d "${4}" ]; then
    error "${4} does not exist or is no directory"
    exit 1
fi

BUNDLE="$(realpath "${2}")"
LICENSE="$(realpath "${3}")"
OUTDIR="$(realpath "${4}")"
BUNDLE_NAME="$(basename "${BUNDLE}" ".app")-v${VERSION}"

info "Packaging Conjugateur version ${VERSION}"

# Define default certificates to sign with.
[ -z "$CERT_PKG" ] && CERT_PKG="Installer"
[ -z "$CERT_APPL" ] && CERT_APPL="Application"
[ -z "$DTARGET" ] && DTARGET="11"

# Define default keychain profile with which to perform notarisation.
[ -z "$NOTARIZE_KC" ] && NOTARIZE_KC="ACPASSWORD"

info "Setting minimum macOS version to \"${DTARGET}\""

# Echo additional debugging info about codesigning.
if [ -z "${NOCODESIGN}" ]; then
    info "Enabling codesigning"
    info "Using Developer ID Installer Certificate \"${CERT_PKG}\""
    info "Using Developer ID Application Certificate \"${CERT_APPL}\""
else
    info "Disabling codesigning and notarisation"
fi

# Define various useful path variables.
COMPONENT_PKG="${OUTDIR}/${BUNDLE_NAME}.component.pkg"
DISTFILE="${OUTDIR}/distfile.plist"
PKG="${OUTDIR}/${BUNDLE_NAME}.pkg"

# Sign the bundle if codesigning is enabled.
if [ -z "${NOCODESIGN}" ]; then
    codesign --sign "${CERT_APPL}" \
        --options runtime \
        --force --timestamp \
        "${BUNDLE}" \
        || exit 1
fi

# Build a component package from the bundle.
pkgbuild --component "${BUNDLE}"\
    --identifier "ch.tifrueh.conjugateur" \
    --version "${VERSION}" \
    --install-location "/Applications" \
    --compression "latest" \
    --min-os-version "${DTARGET}" \
    "${COMPONENT_PKG}" \
|| exit 1

# Synthesise a distfile from the component package.
productbuild --synthesize \
    --package "${COMPONENT_PKG}" \
    "${DISTFILE}" \
|| exit 1

# Insert a line defining the license file into the distfile with awk.
awk -v LIC="${LICENSE}" '
/<\/installer-gui-script>/ {
   print "    <license file=\""LIC"\"\/>"
}
{ print }
' "${DISTFILE}" > "${DISTFILE}.new"

mv -f "${DISTFILE}.new" "${DISTFILE}"

# Build the final installer package, and sign it if codesigning is enabled.
if [ -z "${NOCODESIGN}" ]; then
    productbuild --distribution "${DISTFILE}" \
        --package-path "${OUTDIR}" \
        --sign "${CERT_PKG}" \
        --version "${VERSION}" \
        "${PKG}" \
        || exit 1
else
    productbuild --distribution "${DISTFILE}" \
        --package-path "${OUTDIR}" \
        --version "${VERSION}" \
        "${PKG}" \
        || exit 1
fi

# Notarize the resulting package.
if [ -z "${NONOTARIZE}" ] && [ -z "${NOCODESIGN}" ]; then
    xcrun notarytool \
        submit "${PKG}" \
        -p "${NOTARIZE_KC}" \
        --progress --wait \
        || exit 1
    xcrun stapler staple "${PKG}" \
        || exit 1
fi
