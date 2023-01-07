#!/bin/sh
# See LICENSE file for copyright and license details
BAT=0
for battery in /sys/class/power_supply/BAT?
do
	capacity=$(cat $battery/capacity)
	case $(cat $battery/status) in
		Charging) status=+ ;;
		Discharging) status=- ;;
		*) status=• ;;
	esac
	echo -n [BAT$BAT: $status$capacity]
	((BAT++))
done
