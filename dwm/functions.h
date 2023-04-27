/* scripts */
static const char *shutdowncmd[] = { ".config/dwm/scripts/shutdown.sh", NULL };
static const char *rebootcmd[] = { ".config/dwm/scripts/reboot.sh", NULL };
static const char *exitcmd[] = { ".config/dwm/scripts/exit.sh", NULL };
static const char *transcmd[] = { ".config/dwm/scripts/translate.sh", NULL };

/* volume control */
static const char *volupcmd[] = { "pulsemixer", "--change-volume", "+15", NULL };
static const char *voldowncmd[] = { "pulsemixer", "--change-volume", "-15", NULL };
static const char *mutecmd[] = { "pulsemixer", "--toggle-mute", NULL };
static const char *micmutecmd[] = { "pulsemixer", "--id", "source-1", "--toggle-mute", NULL };

/* screen brightness */
static const char *brupcmd[] = { "brightnessctl", "set", "10%+", NULL };
static const char *brdowncmd[] = { "brightnessctl", "set", "10%-", NULL };

/* screenshot */
static const char *prtscrcmd[] = { "flameshot", "gui", NULL };

/* screen lock (slock) */
static const char *hibernatecmd[] = { "slock", NULL };

/* pass */
static const char *passcmd[] = { "passmenu", NULL };