#!/bin/sh
# Written by Madison Lynch <madi@mxdi.xyz>
# https://deadgirl.dev
[ $(echo -e "No\nYes" | dmenu -i -p "Do you want to exit dwm?") == "Yes" ] && killall dwm slstatus picom fcitx