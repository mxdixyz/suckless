#!/bin/sh
# Written by Madison Lynch <madi@mxdi.xyz>
# https://deadgirl.dev
str=$(dmenu -i -p "English -> 日本語" < /dev/null | trans -no-ansi -s en -t ja)
notify-send "$str"