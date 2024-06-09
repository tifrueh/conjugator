#!/bin/sh

cd "$(dirname "$0")"

msgfmt -o ../lang/fr/LC_MESSAGES/conjugator.mo ../lang/fr/LC_MESSAGES/conjugator.po
