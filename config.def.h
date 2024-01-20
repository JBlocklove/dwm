/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]           = {
	"siji:size=14:antialias=true:autohint=true",
    "monospace:size=10:antialias=true:autohint=true"
};
static const char dmenufont[]       = "monospace:size=10";

static const char normfgcolor[]      = "#b4a4f4";
static const char normbgcolor[]      = "#212337";
static const char normbordercolor[]  = "#212337";
static const char selfgcolor[]       = "#2df4c0";
static const char selbgcolor[]       = "#212337";
static const char selbordercolor[]   = "#04d1f9";
static const char titlefgcolor[]     = "#e4f3fa";
static const char titlebgcolor[]     = "#212337";
static const char titlebordercolor[] = "#212337";
static const char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
	[SchemeTitle] = { titlefgcolor, titlebordercolor, titlebordercolor },
};

static const unsigned int gap		= 12;		/* gap between windows */
static const unsigned int gappih    = gap;       /* horiz inner gap between windows */
static const unsigned int gappiv    = gap;       /* vert inner gap between windows */
static const unsigned int gappoh    = gap;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = gap;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   monitor */
	{ "Arandr",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "Pavucontrol",		NULL,       NULL,       0,            1,			1,           -1 },
	{ "Blueman-manager",	NULL,       NULL,       0,            1,			1,           -1 },
	{ "mpv",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "Sxiv",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "zoom",				NULL,       NULL,       0,            1,			1,           -1 },
	{ "Chromium",			NULL,       NULL,       0,            1,			1,           -1 },
	{ "Ferdium",			NULL,       NULL,       1 << 8,       0,			0,           -1 },
	{ "Signal",				NULL,       NULL,       1 << 8,       0,			0,           -1 },
	{ "St",					NULL,       "neomutt",  1 << 8,       0,			0,           -1 },
	{ "St",					"st_float",	NULL,		0,			  1,			1,			 -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "",      dwindle },
	{ "",		col },
	{ "",      centeredmaster },
	//{ "[]=",      tile },    /* first entry is default */
	//{ "[M]",      monocle },
	//{ "[@]",      spiral },
	//{ "[\\]",     dwindle },
	//{ "H[]",      deck },
	//{ "TTT",      bstack },
	//{ "===",      bstackhoriz },
	//{ "HHH",      grid },
	//{ "###",      nrowgrid },
	//{ "---",      horizgrid },
	//{ ":::",      gaplessgrid },
	//{ "|M|",      centeredmaster },
	//{ ">M>",      centeredfloatingmaster },
	//{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
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
static const Key keys[] = {
	/* modifier                     key        function        argument */
	// DWM Management
	{ MODKEY,                       XK_b,      togglebar,      		{0} },
	{ MODKEY,                       XK_j,      focusstack,     		{.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     		{.i = -1 } },
	{ MODKEY,                       XK_h,      viewprev,			{0} },
	{ MODKEY,                       XK_l,      viewnext,			{0} },
	{ MODKEY|ShiftMask,				XK_j,      movestack,			{.i = +1 } },
	{ MODKEY|ShiftMask,				XK_k,      movestack,      		{.i = -1 } },
	{ MODKEY|Mod1Mask,				XK_i,	   incnmaster,     		{.i = +1 } },
	{ MODKEY|Mod1Mask,			    XK_d,	   incnmaster,     		{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       		{.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       		{.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     		{0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,		{0} },
	{ MODKEY,			            XK_f,      togglefullscr,  		{0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    		{0} },
	{ MODKEY|ShiftMask,				XK_r,	   spawn,		   		SHCMD("$HOME/.local/bin/wm_set_last_wp") },
	{ MODKEY|ControlMask,			XK_r,	   quit,		   		{0} },

	// Run Programs
	{ MODKEY,                       XK_d,      spawn,				{.v = dmenucmd } },
	{ MODKEY,						XK_Return, spawn,          		{.v = termcmd } },
	{ MODKEY,                       XK_i,      spawn,		   		SHCMD("firefox") },
	{ MODKEY,						XK_s,		spawn,         		SHCMD("~/.local/bin/dmenu_ssh")  },
	{ ControlMask|Mod1Mask,			XK_l,		spawn,         		SHCMD("lock")  },
	{ MODKEY|ShiftMask,				XK_p,		spawn,         		SHCMD("passmenu -c -l 20 -z 500")  },
	{ MODKEY,						XK_Print,   spawn,		   		SHCMD("flameshot gui") },
	{ MODKEY,						XK_F6,		spawn,		   		SHCMD("$HOME/.local/bin/wm_toggle_dpms") },
	{ MODKEY,						XK_F7,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_wal_theme") },
	{ MODKEY,						XK_F8,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_monitor") },
	{ MODKEY,						XK_F9,		spawn,		   		SHCMD("$HOME/.config/screenlayout/laptop.sh") },
	{ MODKEY,						XK_F11,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_mount") },
	{ MODKEY,						XK_F12,		spawn,		   		SHCMD("$HOME/.local/bin/dmenu_unmount") },

	{ MODKEY,						XK_t,		spawn,				SHCMD("st -n st_float -g 100x40") },
	{ MODKEY,						XK_u,		spawn,				SHCMD("st -n st_float -g 100x40 -e ranger") },
	{ MODKEY,						XK_c,		spawn,				SHCMD("st -n st_float -g 100x40 -e khal interactive") },
	{ MODKEY,						XK_m,		spawn,				SHCMD("st -n st_float -g 100x40 -e ncmpcpp") },

	// Tags and monitors
	{ MODKEY,                       XK_0,      view,           		{.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            		{.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_h,	   focusmon,       		{.i = -1 } },
	{ MODKEY|ControlMask,           XK_l,	   focusmon,       		{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         		{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         		{.i = +1 } },
	{ MODKEY|ControlMask,			XK_comma,  cyclelayout,    		{.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    		{.i = +1 } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
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
	{ 0,                            XF86XK_AudioNext,        spawn, SHCMD("mpc next") },
	{ 0,                            XF86XK_AudioPrev,        spawn, SHCMD("mpc prev") },
	{ 0,                            XF86XK_AudioPlay,        spawn, SHCMD("mpc toggle") },

	// QUIT
	{ MODKEY|ControlMask,           XK_e,      spawn,				SHCMD("$HOME/.local/bin/dmenu_power") },
};
//static const Key keys[] = {
//	/* modifier                     key        function        argument */
//	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
//	{ MODKEY,						XK_Return, spawn,          {.v = termcmd } },
//	{ MODKEY,                       XK_b,      togglebar,      {0} },
//	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
//	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
//	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
//	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
//	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
//	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
//	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
//	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
//	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
//	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
//	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
//	{ MODKEY,                       XK_Tab,    view,           {0} },
//	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
//	{ MODKEY|ControlMask,		XK_comma,  cyclelayout,    {.i = -1 } },
//	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
//	{ MODKEY,                       XK_space,  setlayout,      {0} },
//	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
//	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
//	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
//	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
//	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
//	{ MODKEY,                       XK_Right,  viewnext,       {0} },
//	{ MODKEY,                       XK_Left,   viewprev,       {0} },
//	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },
//	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },
//	{ MODKEY,						XK_f,		togglefullscr, {0} },
//	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
//	TAGKEYS(                        XK_1,                      0)
//	TAGKEYS(                        XK_2,                      1)
//	TAGKEYS(                        XK_3,                      2)
//	TAGKEYS(                        XK_4,                      3)
//	TAGKEYS(                        XK_5,                      4)
//	TAGKEYS(                        XK_6,                      5)
//	TAGKEYS(                        XK_7,                      6)
//	TAGKEYS(                        XK_8,                      7)
//	TAGKEYS(                        XK_9,                      8)
//	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
//};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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

