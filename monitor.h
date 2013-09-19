#ifndef _MONITOR_H
#define _MONITOR_H

#define DEFAULT_MON_NAME     "Monitor"

monitor_t *make_monitor(xcb_rectangle_t);
monitor_t *find_monitor(char *);
monitor_t *get_monitor_by_id(xcb_randr_output_t);
monitor_t *add_monitor(xcb_rectangle_t);
void remove_monitor(monitor_t *);
void merge_monitors(monitor_t *, monitor_t *);
void swap_monitors(monitor_t *, monitor_t *);
bool import_monitors(void);

#endif
