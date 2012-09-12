#ifndef _MESSAGES_H
#define _MESSAGES_H

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "types.h"

void process_message(char*, char*);
void get_setting(char*, char*);
void set_setting(char*, char*);
void split_ratio_cmd(char *);
bool parse_bool(char *, bool *);
bool parse_layout(char *, layout_t *);
bool parse_direction(char *, direction_t *);
bool parse_cycle_direction(char *, cycle_dir_t *);
bool parse_skip_client(char *, skip_client_t *);
bool parse_fence_move(char *, fence_move_t *);
desktop_t *find_desktop(char *);
void add_desktop(char *);
void alternate_desktop(void);

#endif
