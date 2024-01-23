<div align="center">
    <img src="./resources/conjugateur.svg" alt="Conjugateur icon" width=256 height=256>
    <h1>Conjugateur</h1>
    <a href="https://www.gnu.org/licenses/gpl-3.0.en.html"><img alt="GitHub" src="https://img.shields.io/github/license/tifrueh/conjugateur"></a>
    <a href="https://github.com/tifrueh/conjugateur/releases"><img alt="GitHub tag (with filter)" src="https://img.shields.io/github/v/tag/tifrueh/conjugateur"></a>
    <p></p>
</div>

This application was designed to help students study French verbs. Version 1.0.0 is currently at the end of its development stage and a download of the beta version can be found in the [releases of the GitHub repo](https://github.com/tifrueh/conjugateur/releases). 

## Installation

### macOS (homebrew)

A precompiled version and packaged version for macOS (`>=12`) can be downloaded and installed via my homebrew repository:

1. Tap my homebrew tap

    ~~~
    $ brew tap tifrueh/mytap
    ~~~

2. Install Conjugateur

    ~~~
    $ brew install --cask tifrueh/mytap/conjugateur
    ~~~

### macOS (manual install)

If you don't have homebrew you can also use the installer package for macOS (`>=12`) from the [latest release](https://github.com/tifrueh/conjugateur/releases/latest).

1. Download the installer package

2. Double-click the PKG

3. Follow the installer's instructions

### Windows

An installer executable for x86_64 Windows can be downloaded from the [latest release](https://github.com/tifrueh/conjugateur/releases/latest).

1. Download the installer executable

2. Double-click the EXE

3. Follow the installer's instructions

_Note: As the EXE is not signed, Windows is probably going to warn you about installing untrusted software and it is absolutely right. I'm going to fix this issue in the future, but for the moment, this admittedly insecure installation procedure will have to suffice. I'd recommend you check the integrity of the EXE via the provided SHASUM and choose an installation only for your user, so as not to give the installer root permissions._

### Build from source

If your system is neither macOS nor x86_64 Windows, you'll have to compile and install the program yourself. Additional software components you'll need for that are the following:

- [meson build system](https://mesonbuild.com/)

- [wxwidgets](https://www.wxwidgets.org/)

_Note: If you're building on macOS 10.15 or lower, you'll need to manually set the meson option `macos_min`, as its default value is 11._

## More information

To learn more about Conjugateur, please consult the
[wiki](https://github.com/tifrueh/conjugateur/wiki/).
