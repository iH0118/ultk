#ifndef _ULTK_CANVAS_H
#define _ULTK_CANVAS_H

#include <ultk/ultk_common.h>
#include <ultk/ultk_widget.h>
#include <ultk/ultk_uidl_uib.h>

typedef int                   ultk_canvas_id_t;
typedef struct ultk_canvas    ultk_canvas_t;

struct ultk_canvas {
    ultk_canvas_type_t type;
    char *id;
    char *title;
    struct {
        ultk_screen_coord_t x;
        ultk_screen_coord_t y;
    } size;
    ultk_widget_t *widget_top;
};

#endif