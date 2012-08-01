#ifndef _MAIN_H
#define _MAIN_H

#define INPUT_FIFO      "/tmp/bspwm-input"

xcb_connection_t *dpy;
int default_screen, screen_width, screen_height;
xcb_screen_t *screen;
bool running;

static char *WM_ATOM_NAME[]   = { "WM_PROTOCOLS", "WM_DELETE_WINDOW" };
static char *NET_ATOM_NAME[]  = { "_NET_SUPPORTED", "_NET_WM_STATE_FULLSCREEN", "_NET_WM_STATE", "_NET_ACTIVE_WINDOW" };

enum { WM_PROTOCOLS, WM_DELETE_WINDOW, WM_COUNT };
enum { NET_SUPPORTED, NET_FULLSCREEN, NET_WM_STATE, NET_ACTIVE, NET_COUNT };

static xcb_atom_t wmatoms[WM_COUNT], netatoms[NET_COUNT];

int xcb_check_other_wm(void);
xcb_screen_t *xcb_screen_of_display(xcb_connection_t*, int);
void sigchld(int);
void setup(int);

#endif
