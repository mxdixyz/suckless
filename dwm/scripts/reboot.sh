#!/bin/sh
# Written by Madison Lynch <madi@mxdi.xyz>
# https://deadgirl.dev
[ $(echo -e "No\nYes" | dmenu -i -p "Do you want to reboot?") == "Yes" ] && reboot