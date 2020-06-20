#!/bin/bash

PROJECT_NAME=CMakeWidgetProject
ICON_SET=${PROJECT_NAME}.iconset
mkdir ${ICON_SET}

ICON_NAME=technology.svg
qlmanage -t -s 1024 -o . ${ICON_NAME}


sips -z 16   16     ${ICON_NAME}.png --out ${ICON_SET}/icon_16x16.png
sips -z 32   32     ${ICON_NAME}.png --out ${ICON_SET}/icon_16x16@2x.png
sips -z 32   32     ${ICON_NAME}.png --out ${ICON_SET}/icon_32x32.png
sips -z 64   64     ${ICON_NAME}.png --out ${ICON_SET}/icon_32x32@2x.png
sips -z 128  128    ${ICON_NAME}.png --out ${ICON_SET}/icon_128x128.png
sips -z 256  256    ${ICON_NAME}.png --out ${ICON_SET}/icon_128x128@2x.png
sips -z 256  256    ${ICON_NAME}.png --out ${ICON_SET}/icon_256x256.png
sips -z 512  512    ${ICON_NAME}.png --out ${ICON_SET}/icon_256x256@2x.png
sips -z 512  512    ${ICON_NAME}.png --out ${ICON_SET}/icon_512x512.png
sips -z 1024 1024   ${ICON_NAME}.png --out ${ICON_SET}/icon_512x512@2x.png

iconutil -c icns ${ICON_SET}

