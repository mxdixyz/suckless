#!/bin/sh
# Written by Madison Lynch <madi@mxdi.xyz>
# https://deadgirl.dev

USR=$(logname)
DIR=/home/$USR/.config/dwm

if [ "$1" == "init" ]; then
	printf "Creating scripts directory at %s\n" $DIR
	mkdir -p $DIR
	cp -f scripts/* $DIR

	printf "Transferring ownership to %s\n" $USR
	chown -R $USR:$(groups $USR) $DIR .
	chmod 755 $DIR/*
elif [ "$1" == "remove" ]; then
	printf "Removing scripts directory at %s\n" $DIR
	rm -rf $DIR
else
	printf "Invalid/no arguments\n"
fi