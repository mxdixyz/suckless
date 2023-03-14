/* See LICENSE file for copyright and license details. */
const unsigned int interval = 1000;
static const char unknown_str[] = "n/a";
#define MAXLEN 2048
 
static const struct arg args[] = {
	/* function		format			argument						*/
	{ cpu_perc,		"[ %s%%]",		NULL							},
	{ ram_perc, 	"[ %s%% - ",	NULL							},
	{ ram_used, 	"%s] | ",		NULL							},
	{ run_command,	"%s",			"suckless/slstatus/dynbat.sh"	},
	{ kanji,		" | (%s) ",		NULL							},
	{ datetime,		"%s ",			"%D | %T"						},
};