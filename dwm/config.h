/* See LICENSE file for copyright and license details */
static const unsigned int borderpx  = 2;            // border pixel of windows
static const unsigned int gappx     = 5;            // gaps between windows
static const unsigned int snap      = 32;           // snap pixel
static const int swallowfloating    = 1;            // 1 means swallow floating windows by default
static const int showbar            = 1;            // 0 means no bar
static const int topbar             = 1;            // 0 means bottom bar
static const char *fonts[]          = { "monospace:size=12", "ttf-ibm-plex:size=12", "FontAwesome:size=12" };
static const char dmenufont[]       = "monospace:size=12";
static const char col_gray1[]       = "#222222";    // background color
static const char col_gray2[]       = "#333333";    // unfocused window border color
static const char col_gray3[]       = "#ffffff";    // font color
static const char col_gray4[]       = "#ffffff";    // tag label color
static const char col_cyan[]        = "#1793d1";    // current tag/active window border color
static const char *colors[][3]      = {
    /*             fg           bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "I", "II", "III", "IV", "V" };
static const Rule rules[] = {
    /* xprop(1):
     *    WM_CLASS(STRING) = instance, class
     *    WM_NAME(STRING) = title
     */
    /* class     instance     title            tags mask     isfloating    monitor */
    { "Gimp",    NULL,        NULL,            0,            1,            -1, },
    { "Firefox", NULL,        NULL,            0,            0,            -1, },
};

/* layout(s) */
static const float mfact     = 0.55;     // factor of master area size [0.05..0.95]
static const int nmaster     = 1;        // number of clients in master area
static const int resizehints = 1;        // 1 means respect size hints in tiled resizals
static const int attachbelow = 1;        // 1 means attach after the currently active window
static const int lockfullscreen = 1;     // 1 will force focus on the fullscreen window
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    // first entry is default
    { "><>",      NULL },    // no layout function means floating behavior
    { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask                // MODKEY = super key (windows key)
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, "-hp", "chromium,librewolf", NULL };
static const char *termcmd[]  = { "urxvt", NULL };

#include <X11/XF86keysym.h>
#include "functions.h"
#include "push.c"
static Key keys[] = {
    // modifier                      key          function          argument
    { MODKEY,                        XK_space,    spawn,            {.v = dmenucmd            } },
    { MODKEY|ShiftMask,              XK_Return,   spawn,            {.v = termcmd             } },
    { MODKEY|ControlMask,            XK_q,        quit,             {0                        } },
    { MODKEY,                        XK_b,        togglebar,        {0                        } },
    { MODKEY,                        XK_j,        focusstack,       {.i = -1                  } },
    { MODKEY,                        XK_k,        focusstack,       {.i = +1                  } },
    { MODKEY,                        XK_i,        incnmaster,       {.i = +1                  } },
    { MODKEY,                        XK_o,        incnmaster,       {.i = -1                  } },
    { MODKEY,                        XK_h,        setmfact,         {.f = -0.05               } },
    { MODKEY,                        XK_l,        setmfact,         {.f = +0.05               } },
    { MODKEY,                        XK_Return,   zoom,             {05                       } },
    { MODKEY,                        XK_Tab,      view,             {05                       } },
    { MODKEY|ShiftMask,              XK_c,        killclient,       {05                       } },
    { MODKEY,                        XK_t,        setlayout,        {.v = &layouts[0]         } },
    { MODKEY,                        XK_f,        setlayout,        {.v = &layouts[1]         } },
    { MODKEY,                        XK_m,        setlayout,        {.v = &layouts[2]         } },
    { MODKEY,                        XK_p,        setlayout,        {0                        } },
    { MODKEY,                        XK_0,        view,             {.ui = ~0                 } },
    { MODKEY|ShiftMask,              XK_0,        tag,              {.ui = ~0                 } },
    { MODKEY,                        XK_comma,    focusmon,         {.i = -1                  } },
    { MODKEY,                        XK_period,   focusmon,         {.i = +1                  } },
    { MODKEY|ShiftMask,              XK_comma,    tagmon,           {.i = -1                  } },
    { MODKEY|ShiftMask,              XK_period,   tagmon,           {.i = +1                  } },
    // dmenu scripts
    { MODKEY|ShiftMask,              XK_s,        spawn,            {.v = shutdowncmd         } },    // dmenu prompt to shutdown
    { MODKEY|ShiftMask,              XK_r,        spawn,            {.v = rebootcmd           } },    // dmenu prompt to reboot
    { MODKEY|ShiftMask,              XK_q,        spawn,            {.v = exitcmd             } },    // dmenu prompt to exit dwm
    // patches
    { MODKEY,                        XK_minus,    setgaps,          {.i = -1                  } },    // decrease gap size
    { MODKEY,                        XK_equal,    setgaps,          {.i = +1                  } },    // increase gap size
    { MODKEY|ShiftMask,              XK_equal,    setgaps,          {.i = 0                   } },    // set gap size to 0
    { MODKEY|ShiftMask,              XK_j,        pushup,           {0                        } },    // push active window up stack
    { MODKEY|ShiftMask,              XK_k,        pushdown,         {05                       } },    // push active window down stack
    // hardware keys
    { 0,             XF86XK_AudioRaiseVolume,     spawn,            {.v = volupcmd            } },    // increase audio volume by 10%
    { 0,             XF86XK_AudioLowerVolume,     spawn,            {.v = voldowncmd          } },    // decrease audio volume by 10%
    { 0,             XF86XK_AudioMute,            spawn,            {.v = mutecmd             } },    // mute audio
    { 0,             XF86XK_AudioMicMute,         spawn,            {.v = micmutecmd          } },    // mute microphone (source-1)
    { 0,             XF86XK_MonBrightnessUp,      spawn,            {.v = brupcmd             } },    // increase  brightness by 10%
    { 0,             XF86XK_MonBrightnessDown,    spawn,            {.v = brdowncmd           } },    // decrease brightness by 10%
    { 0,             XK_Scroll_Lock,              spawn,            {.v = hibernatecmd        } },    // lock screen (slock)
    { 0,             XK_Print,                    spawn,            {.v = prtscrcmd           } },    // screenshot (flameshot gui)
    // tags
    TAGKEYS(                         XK_1,                          0                           )
    TAGKEYS(                         XK_2,                          1                           )
    TAGKEYS(                         XK_3,                          2                           )
    TAGKEYS(                         XK_4,                          3                           )
    TAGKEYS(                         XK_5,                          4                           )
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0                } },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2] } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0                } },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0                } },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0                } },
    { ClkTagBar,            0,              Button1,        view,           {0                } },
    { ClkTagBar,            0,              Button3,        toggleview,     {0                } },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0                } },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0                } },
};
