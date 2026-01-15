#ifndef _ULTK_CANVAS_H
#define _ULTK_CANVAS_H

#include <ultk/ultk_common.h>
#include <ultk/ultk_widget.h>

typedef int                   ultk_canvas_id_t;
typedef enum ultk_canvas_type ultk_canvas_type_t;
typedef struct ultk_canvas    ultk_canvas_t;

enum ultk_canvas_type {
    ULTK_CANVAS_NULL,
    ULTK_CANVAS_APPLICATION,
    ULTK_CANVAS_UTILITY,
    ULTK_CANVAS_POPUP_MENU,
    ULTK_CANVAS_TOOLTIP
};

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