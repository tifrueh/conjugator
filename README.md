<div align="center">
    <img src="resources/conjugator.png" alt="Conjugator icon" width=256 height=256>
    <h1>Conjugator</h1>
    <a href="https://www.gnu.org/licenses/gpl-3.0.en.html">
        <img alt="GitHub" src="https://img.shields.io/github/license/tifrueh/conjugator" /></a>
    <a href="https://github.com/tifrueh/conjugator/releases/latest">
        <img alt="GitHub tag (with filter)" src="https://img.shields.io/github/v/tag/tifrueh/conjugator" /></a>
    <p></p>
</div>

This application is designed to help students study verbs. The latest release
can be downloaded from the [releases of the GitHub
repo](https://github.com/tifrueh/conjugator/releases/latest). 

## Features

- Generate a quiz which asks you to conjugate 15 different verbs

- Select which verb types and which tenses you want to be asked about

- Get feedback on the correctness of your answers without showing solutions

- Compare your answer to the solutions

- Read up on the conjugation of all verbs in the app's database using the
  separate "Inspecteur" window

## Installation

### macOS (homebrew)

A compiled and packaged version for macOS (`>=12`) can be downloaded and
installed via my homebrew repository:

1. Tap my homebrew tap

    ~~~
    $ brew tap tifrueh/mytap
    ~~~

2. Install Conjugator

    ~~~
    $ brew install --cask tifrueh/mytap/conjugator
    ~~~

### macOS (PGK install)

If you don't have homebrew you can also use the installer package for macOS
(`>=12`) from the [latest
release](https://github.com/tifrueh/conjugator/releases/latest).

1. Download the installer package

2. Double-click the PKG

3. Follow the installer's instructions

### macOS (DMG install)

If you'd rather not use an installer package, you can also download the
application packaged in a DMG for macOS (`>=12`) from the [latest
release](https://github.com/tifrueh/conjugator/releases/latest).

1. Download the DMG

2. Double-click the DMG

3. Drag the application to the location where you want to have it (e. g.
   `~/Applications` or `/Applications`)

### Windows

An installer executable for x86_64 Windows can be downloaded from the [latest
release](https://github.com/tifrueh/conjugator/releases/latest).

1. Download the installer executable

2. Double-click the EXE

3. Follow the installer's instructions

_Note: As the EXE is not signed, Windows is probably going to warn you about
installing untrusted software and it is absolutely right. I'd recommend you
check the integrity of the EXE via the provided SHASUM and choose an
installation only for your user, so as not to give the installer root
permissions._

### Build from source

If your system is neither macOS nor x86_64 Windows, you'll have to compile and
install the program yourself. Instructions can be found in the
[wiki](https://github.com/tifrueh/conjugator/wiki/02-Building).

## More information

To learn more about Conjugator, please consult the
[wiki](https://github.com/tifrueh/conjugator/wiki/).
