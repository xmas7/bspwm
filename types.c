#include <stdlib.h>
#include <string.h>
#include <xcb/xcb.h>
#include <xcb/xcb_event.h>
#include "types.h"

node_t *make_node(void)
{
    node_t *n = malloc(sizeof(node_t));
    n->parent = n->first_child = n->second_child = NULL;
    n->split_ratio = SPLIT_RATIO;
    n->split_type = TYPE_VERTICAL;
    n->client = NULL;
    n->vacant = false;
    return n;
}

desktop_t *make_desktop(const char *name)
{
    desktop_t *d = malloc(sizeof(desktop_t));
    strncpy(d->name, name, sizeof(d->name));
    d->layout = LAYOUT_TILED;
    d->prev = d->next = NULL;
    d->root = d->focus = d->last_focus = NULL;
    return d;
}

client_t *make_client(xcb_window_t win)
{
    client_t *c = malloc(sizeof(client_t));
    c->window = win;
    c->floating = c->transient = c->fullscreen = c->locked = false;
    return c;
}

rule_t *make_rule(void)
{
    rule_t *r = malloc(sizeof(rule_t));
    r->cause.class_name = r->cause.instance_name = NULL;
    r->effect.floating = r->effect.fullscreen = r->effect.locked = r->effect.centered = false;
    return r;
}
