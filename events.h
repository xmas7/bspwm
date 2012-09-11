#ifndef _EVENTS_H
#define _EVENTS_H

#include <xcb/xcb.h>
#include <xcb/xcb_event.h>

void handle_event(xcb_generic_event_t *);
void map_request(xcb_generic_event_t *);
void client_message(xcb_generic_event_t *);
void handle_state(node_t *, xcb_atom_t, unsigned int);

#endif
