#!/bin/sh

# ${1} is the directory containing the .gcno files (%{buildDir} in Qt Creator)

LCOV=lcov
GENHTML=genhtml
BROWSER="/Applications/Google Chrome.app/Contents/MacOS/Google Chrome"

SRC_DIR="${1}"
HTML_RESULTS="${1}/html"

mkdir -p ${HTML_RESULTS}

# generate our initial info
"${LCOV}" -d "${SRC_DIR}" -c -o "${SRC_DIR}/coverage.info"

# remove some paths
"${LCOV}" -r "${SRC_DIR}/coverage.info" "*Qt*.framework*" "*Xcode.app*" "*.moc" "*moc_*.cpp" "*/test/*" -o "${SRC_DIR}/coverage-filtered.info"

# generate our HTML
"${GENHTML}" -o "${HTML_RESULTS}" "${SRC_DIR}/coverage-filtered.info"

# reset our counts
"${LCOV}" -d "${SRC_DIR}" -z

# open in browser and bring to front
"${BROWSER}" "${HTML_RESULTS}/index.html"
open -a "${BROWSER}"
