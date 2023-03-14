#!/bin/sh
[ $(echo -e "No\nYes" | dmenu -i -p "Do you want to exit dwm?") == "Yes" ] && killall dwm slstatus picom fcitx
