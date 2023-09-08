#!/bin/sh

parent_path=$( cd "$(dirname "$0")" ; pwd -P )

cd "$parent_path"


APP=Conjugateur.app
CONTENTS_PATH=$APP/Contents
RES_PATH=$CONTENTS_PATH/Resources
EXE_PATH=$CONTENTS_PATH/MacOS
LC_DE_PATH=$RES_PATH/fr.lproj

rm -rf $APP
mkdir $APP

install -d -m 755 $CONTENTS_PATH $RES_PATH $EXE_PATH $LC_DE_PATH

install -m 644 ../../resources/Info.plist $CONTENTS_PATH
install -m 644 ../../resources/lang/fr/LC_MESSAGES/wxstd.mo $LC_DE_PATH
install -m 644 ../../resources/conjugateur.icns $RES_PATH
install -s -m 755 ../../build/conjugateur $EXE_PATH
