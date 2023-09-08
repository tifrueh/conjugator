#!/bin/sh

parent_path=$( cd "$(dirname "$0")" ; pwd -P )

cd "$parent_path"

echo "----=SIGNING=----"

codesign --force --verbose=2 --timestamp --sign $CERT_APPL --options runtime Conjugateur.app

echo "-----------------\n"

echo "---=VERIFYING=---"

codesign --verbose=2 --verify Conjugateur.app

echo "-----------------\n"
