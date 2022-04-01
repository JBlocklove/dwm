/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */

// GAPS
static const unsigned int gap		= 20;
static const unsigned int gappih    = gap;       /* horiz inner gap between windows */
static const unsigned int gappiv    = gap;       /* vert inner gap between windows */
static const unsigned int gappoh    = gap;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = gap;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

// BAR
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

// FONTS
static const char *fonts[]           = {
    "IBM Plex Mono:size=11:antialias=true:autohint=true",
	"siji:size=14:antialias=true:autohint=true"
};
static const char dmenufont[]        = "monospace:size=10";

// COLORS
static const char normfgcolor[]      = "#bfbfbf";
static const char normbgcolor[]      = "#262626";
static const char normbordercolor[]  = "#262626";
static const char selfgcolor[]       = "#ffffff";
static const char selbgcolor[]       = "#262626";
static const char selbordercolor[]   = "#666666";
static const char titlefgcolor[]     = "#ffffff";
static const char titlebgcolor[]     = "#262626";
static const char titlebordercolor[] = "#262626";
static const char *colors[][3]       = {
	/*                fg            bg                border   */
	[SchemeNorm]  = { normfgcolor,  normbgcolor,      normbordercolor },
	[SchemeSel]   = { selfgcolor,   selbgcolor,       selbordercolor },
	[SchemeTitle] = { titlefgcolor, titlebordercolor, titlebordercolor },
};

static const unsigned int baralpha = 0x90;
static const unsigned int borderalpha = 0x90;

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTitle] = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
//const char *spcmd1[] = {"urxvt", "-name", "spmusic", "-geometry", "100x35", "-e", "ncmpcpp", NULL };
const char *spcmd1[] = {"st", "-n", "spmusic", "-g", "100x35", "-e", "ncmpcpp", NULL };
const char *spcmd2[] = {"st", "-n", "spnews", "-g", "100x35", "-e", "newsboat", NULL };
const char *spcmd3[] = {"st", "-n", "spterm", "-g", "100x35", NULL };
const char *spcmd4[] = {"st", "-n", "spfm", "-g", "80x40", "-e", "ranger", NULL };
const char *spcmd5[] = {"st", "-n", "spwal", "-g", "100x35", "-e", "ranger", "/home/jason/Pictures/Wallpapers", NULL };
const char *spcmd6[] = {"st", "-n", "spcal", "-g", "100x50", "-e", "calcurse", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spmusic",		spcmd1},
	{"spnews",		spcmd2},
	{"spterm",		spcmd3},
	{"spfm",		spcmd4},
	{"spwal",		spcmd5},
	{"spcal",		spcmd6},
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "", "", "", "", "", "", "", "", ""};
//static const char *tags[] = { "", "", "", "", "", "", "", "", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class				instance    title       tags mask   iscentered	isfloating   monitor */
	{ "Galculator",			NULL,       NULL,       0,            1,			1,           -1 },
	{ "Arandr",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "Pavucontrol",		NULL,       NULL,       0,            1,			1,           -1 },
	{ "Blueman-manager",	NULL,       NULL,       0,            1,			1,           -1 },
	{ "mpv",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "Sxiv",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "zoom",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "discord",			NULL,       NULL,       1 << 7,       0,			0,           -1 },
	{ "Signal",				NULL,       NULL,       1 << 7,       0,			0,           -1 },
	{ "St",					NULL,       "neomutt",  1 << 8,       0,			0,           -1 },
	{ NULL,					"spmusic",	NULL,		SPTAG(0),	  1,			1,			 -1 },
	{ NULL,					"spnews",	NULL,		SPTAG(1),	  1,			1,			 -1 },
	{ NULL,					"spterm",	NULL,		SPTAG(2),	  1,			1,			 -1 },
	{ NULL,					"spfm",		NULL,		SPTAG(3),	  1,			1,			 -1 },
	{ NULL,					"spwal",	NULL,		SPTAG(4),	  1,			1,			 -1 },
	{ NULL,					"spcal",	NULL,		SPTAG(5),	  1,			1,			 -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "",      dwindle },
	//{ "",      tile },    /* first entry is default */
	{ "",		col },
	{ "",		bstack },
	//{ "",      NULL },    /* no layout function means floating behavior */
	{ NULL,		 NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-c","-l", "20", "-z", "500", NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
#include <X11/XF86keysym.h>


static Key keys[] = {
	/* modifier                     key        function				argument */
	{ MODKEY,                       XK_b,      togglebar,      		{0} },
	{ MODKEY,                       XK_j,      focusstack,     		{.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     		{.i = -1 } },
	{ MODKEY,                       XK_h,      shiftviewclients,    {.i = -1 } },
	{ MODKEY,                       XK_l,      shiftviewclients,	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,			{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      		{.i = -1 } },
	{ MODKEY|ShiftMask,				XK_i,	   incnmaster,     		{.i = +1 } },
	{ MODKEY|ShiftMask,			    XK_d,	   incnmaster,     		{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       		{.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       		{.f = +0.05} },
	{ MODKEY,                       XK_Tab,    view,           		{0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     		{0} },
	//{ MODKEY,                       XK_space,  setlayout,			{0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,		{0} },
	{ MODKEY,			            XK_f,      togglefullscr,  		{0} },
	{ MODKEY,                       XK_0,      view,           		{.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            		{.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_h,	   focusmon,       		{.i = -1 } },
	{ MODKEY|ControlMask,           XK_l,	   focusmon,       		{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         		{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         		{.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     		{0} },
	{ MODKEY|ControlMask,			XK_comma,  cyclelayout,    		{.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    		{.i = +1 } },
	{ MODKEY|ShiftMask,				XK_r,	   spawn,		   		SHCMD("$HOME/.local/bin/wm_set_last_wp") },
	{ MODKEY|ControlMask,			XK_r,	   quit,		   		{0} },

	// Run Programs
	{ MODKEY,                       XK_d,      spawn,          		{.v = dmenucmd } },
	{ MODKEY,				        XK_Return, spawn,          		{.v = termcmd } },
	{ MODKEY,						XK_i,		spawn,         		SHCMD("firefox")  },
	{ MODKEY,						XK_s,		spawn,         		SHCMD("~/.local/bin/dmenu_ssh")  },
	{ ControlMask|Mod1Mask,			XK_l,		spawn,         		SHCMD("lock")  },
	{ MODKEY|ShiftMask,				XK_p,		spawn,         		SHCMD("passmenu -c -l 20 -z 500")  },
	{ MODKEY,						XK_Print,   spawn,		   		SHCMD("maim -u -o -s ~/Pictures/Screenshots/$(date +%s).png") },
	{ MODKEY,						XK_F6,		spawn,		   		SHCMD("$HOME/.local/bin/wm_toggle_dpms") },
	{ MODKEY,						XK_F7,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_wal_theme") },
	{ MODKEY,						XK_F8,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_monitor") },
	{ MODKEY,						XK_F11,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_mount") },
	{ MODKEY,						XK_F12,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_unmount") },
	{ MODKEY,            			XK_m,		togglescratch,		{.ui = 0 } },
	{ MODKEY,            			XK_n,	    togglescratch,  	{.ui = 1 } },
	{ MODKEY,						XK_u,		togglescratch,  	{.ui = 3 } },
	{ MODKEY,						XK_c,		togglescratch,  	{.ui = 5 } },
	{ MODKEY,						XK_t,		togglescratch,  	{.ui = 2 } },
	{ MODKEY,						XK_w,		togglescratch,  	{.ui = 4 } },

	// Tag navigation
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	// XF86 Keys
	{ 0,                            XF86XK_AudioMute,        spawn, SHCMD("$HOME/.local/bin/dunst_volume_control mute") },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, SHCMD("$HOME/.local/bin/dunst_volume_control down") },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, SHCMD("$HOME/.local/bin/dunst_volume_control up") },
	{ 0,                            XF86XK_MonBrightnessUp,  spawn, SHCMD("$HOME/.local/bin/dunst_brightness_control up") },
	{ 0,                            XF86XK_MonBrightnessDown,spawn, SHCMD("$HOME/.local/bin/dunst_brightness_control down") },
	{ 0,                            XF86XK_AudioNext,        spawn, SHCMD("playerctl -p mopidy next") },
	{ 0,                            XF86XK_AudioPrev,        spawn, SHCMD("playerctl -p mopidy previous") },
	{ 0,                            XF86XK_AudioPlay,        spawn, SHCMD("playerctl -p mopidy play-pause") },

	// QUIT
	{ MODKEY|ControlMask,           XK_e,      spawn,				SHCMD("$HOME/.local/bin/dmenu_power") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
