#!/bin/sh
BAT=0
for battery in /sys/class/power_supply/BAT?
do
	capacity=$(cat $battery/capacity)
	case $(cat $battery/status) in
		Charging) status=+ ;;
		Discharging) status=- ;;
		*) status=• ;;
	esac
	printf "[BAT%i: %s%i]" $BAT $status $capacity
	((BAT++))
done