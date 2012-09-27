#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <xcb/xcb.h>
#include <xcb/xcb_event.h>
#include "helpers.h"
#include "types.h"
#include "bspwm.h"
#include "misc.h"
#include "common.h"
#include "settings.h"

void run_autostart(void)
{
    char path[MAXLEN];

    snprintf(path, sizeof(path), "%s/%s/%s", getenv("XDG_CONFIG_HOME"), WM_NAME, AUTOSTART_FILE);

    if (fork() != 0)
        return;

    if (dpy != NULL)
        close(xcb_get_file_descriptor(dpy));

    setsid();
    execl(path, path, NULL);
        
    PUTS("error: could not load autostart file");
    exit(EXIT_SUCCESS);
}

void load_settings(void)
{
    strcpy(normal_border_color, NORMAL_BORDER_COLOR);
    strcpy(active_border_color, ACTIVE_BORDER_COLOR);
    strcpy(inner_border_color, INNER_BORDER_COLOR);
    strcpy(outer_border_color, OUTER_BORDER_COLOR);
    strcpy(presel_border_color, PRESEL_BORDER_COLOR);
    strcpy(active_locked_border_color, ACTIVE_LOCKED_BORDER_COLOR);
    strcpy(normal_locked_border_color, NORMAL_LOCKED_BORDER_COLOR);
    strcpy(urgent_border_color, URGENT_BORDER_COLOR);

    normal_border_color_pxl = get_color(normal_border_color);
    active_border_color_pxl = get_color(active_border_color);
    inner_border_color_pxl = get_color(inner_border_color);
    outer_border_color_pxl = get_color(outer_border_color);
    presel_border_color_pxl = get_color(presel_border_color);
    active_locked_border_color_pxl = get_color(active_locked_border_color);
    normal_locked_border_color_pxl = get_color(normal_locked_border_color);
    urgent_border_color_pxl = get_color(urgent_border_color);

    strcpy(wm_name, WM_NAME);
    adaptive_window_border = ADAPTIVE_WINDOW_BORDER;

    inner_border_width = INNER_BORDER_WIDTH;
    main_border_width = MAIN_BORDER_WIDTH;
    outer_border_width = OUTER_BORDER_WIDTH;

    border_width = inner_border_width + main_border_width + outer_border_width;

    window_gap = WINDOW_GAP;
    left_padding = LEFT_PADDING;
    right_padding = RIGHT_PADDING;
    top_padding = TOP_PADDING;
    bottom_padding = BOTTOM_PADDING;
}
