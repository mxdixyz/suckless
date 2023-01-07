#!/bin/sh
# Opens a prompt in dmenu to reboot the system
[ $(echo -e "No\nYes" | dmenu -i -p "Do you want to reboot?") == "Yes" ] && reboot
