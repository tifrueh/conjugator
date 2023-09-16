# Conjugateur

This application was designed to help students study french verbs. Version 1.0.0 is currently at the end of its development stage and a dowload of the alpha version can be found in the [releases of the GitHub repo](https://github.com/tifrueh/conjugateur/releases). 

## Installation

### macOS (homebrew)

A precompiled version and packaged version for macOS can be downloaded and installed via my homebrew repository:

1. Tap my homebrew tap

~~~
$ brew tap tifrueh/mytap
~~~

2. Install Conjugateur

~~~
$ brew install --cask tifrueh/mytap/conjugateur
~~~

### macOS (manual install)

If you don't have homebrew you can also use the installer package for macOS from the [latest release](https://github.com/tifrueh/conjugateur/releases/latest).

1. Download the installer package

2. Double-click the PKG

3. Follow the installer's instructions

### Windows

Unfortunately there is no Windows version at the moment, but you should be able to compile the application using the source code provided in the [latest release](https://github.com/tifrueh/conjugateur/releases/latest) nonetheless.

Additional software components needed:

- [meson](https://mesonbuild.com/SimpleStart.html)
- [wxWidgets](https://www.wxwidgets.org/downloads/)

## Preview (macOS)

![macOS preview](./resources/preview.png)

## Usage

There are two distinct sections in the application's GUI:

1. [**Sélection des verbes/tems**](#sélection-des-verbestemps)

2. [**Quiz**](#quiz)

### Sélection des verbes/temps

This panel is used to control the **Quiz** section of the app. Firstly, under the header **Types de verbes** you can select which kinds of verbs will be used in the quiz and under the header **Tems** you can select the tenses which will be used in the quiz.

The button **Gérer** generates a new quiz.

The button **Contrôler** checks the correctness of the answers in the quiz and marks them in different colours.

The button **Solutions** checks the verbs and also shows the correct solutions.

### Quiz

This panel displays a total of 20 text entries plus the infitinive, a tense and a personal pronoun. You can now try to put the correct verb form into the text entry and then use the buttons to the bottom left (see [previous section](#sélection-des-verbestemps)) to check your answers or show the solutions.

### Keyboard shortcuts

`Ctrl+1`: Select all verbs

`Ctrl+2`: Select all tenses

`Ctrl+0`: Unselect all verbs and tenses

`Ctrl+Enter`: Generate new quiz

`Ctrl+Shift+Enter`: Check answers

`Ctrl+S`: Show solutions

_Note: `Ctrl` corresponds to `Cmd` on macOS systems_

## Verbs

The following verbs are being used by the application as of this version:

- acheter

- agir

- aller

- amener

- apercevoir

- apparaître

- appeler

- applaudir

- appuyer

- atteindre

- avancer

- avoir

- battre

- bavarder

- boire

- choisir

- conduire

- confondre

- connaître

- construire

- courir

- couvrir

- craindre

- coire

- cueillir

More verbs will be added in the near future.
