/* See LICENSE file for copyright and license details. */
static int topbar = 1;
static const char *fonts[] = {
	"monospace:size=12"
};
static const char *prompt = NULL;
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#bbbbbb", "#333333" },
	[SchemeSel] = { "#eeeeee", "#1793d1" },
	[SchemeOut] = { "#000000", "#00ffff" },
	[SchemeHp]  = { "#bbbbbb", "#333333" }
};
static unsigned int lines = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
