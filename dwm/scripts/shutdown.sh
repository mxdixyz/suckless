#!/bin/sh
# Opens a prompt in dmenu to shutdown the system
[ $(echo -e "No\nYes" | dmenu -i -p "Do you want to shutdown?") == "Yes" ] && shutdown now
