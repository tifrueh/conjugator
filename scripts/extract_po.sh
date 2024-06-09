#!/bin/sh

cd "$(dirname "$0")"

xgettext -C -k_ --from-code=utf-8 \
    -o ../lang/fr/LC_MESSAGES/conjugator.po \
    --omit-header \
    --join-existing \
    ../src/*.cpp
