#!/bin/sh
# Opens a prompt in dmenu to quit out of dwm
[ $(echo -e "No\nYes" | dmenu -i -p "Do you want to exit dwm?") == "Yes" ] && killall dwm
