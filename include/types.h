#ifndef ULTK_TYPES_H
#define ULTK_TYPES_H

#include <stdint.h>

typedef int                        ultk_return_t;
typedef unsigned int               ultk_screen_coord_t;
typedef unsigned int               ultk_canvas_id_t;
typedef enum ultk_color_index      ultk_color_index_t;
typedef enum ultk_widget_type      ultk_widget_type_t;
typedef enum ultk_input_event_type ultk_input_event_type_t;
typedef union ultk_color_rgba      ultk_color_rgba_t;
typedef struct ultk_canvas         ultk_canvas_t;
typedef struct ultk_widget         ultk_widget_t;
typedef struct ultk_input_state    ultk_input_state_t;
typedef struct ultk_input_event    ultk_input_event_t;

enum ultk_color_index {
    ULTK_COLOR_BACKGROUND,
    ULTK_COLOR_BUTTON_BORDER,
    ULTK_COLOR_BUTTON_FILL,
    ULTK_COLOR_BUTTON_FILL_ACTIVE,
    ULTK_COLOR_BUTTON_FILL_HOVER,
    ULTK_COLOR_CHECKBOX_BORDER,
    ULTK_COLOR_CHECKBOX_FILL,
    ULTK_COLOR_CHECKBOX_FILL_ACTIVE,
    ULTK_COLOR_CHECKBOX_FILL_HOVER,
    ULTK_COLOR_CHECKBOX_CHECKMARK,
    ULTK_COLOR_CONTAINER_BACKGROUND,
    ULTK_COLOR_CONTAINER_BORDER,
    ULTK_COLOR_CONTAINER_SEPARATOR,
    ULTK_COLOR_PROGRESSBAR_BORDER,
    ULTK_COLOR_PROGRESSBAR_FILL,
    ULTK_COLOR_PROGRESSBAR_FILL_ACTIVE,
    ULTK_COLOR_RADIOBUTTON_BORDER,
    ULTK_COLOR_RADIOBUTTON_FILL,
    ULTK_COLOR_RADIOBUTTON_FILL_ACTIVE,
    ULTK_COLOR_RADIOBUTTON_FILL_HOVER,
    ULTK_COLOR_TEXT
};

enum ultk_widget_type {
    ULTK_WIDGET_VOID,
    ULTK_WIDGET_BUTTON,
    ULTK_WIDGET_CHECKBOX,
    ULTK_WIDGET_CONTAINER,
    ULTK_WIDGET_CONTAINER_SPLIT,
    ULTK_WIDGET_CONTAINER_GRID,
    ULTK_WIDGET_PROGRESSBAR,
    ULTK_WIDGET_RADIOBUTTONS,
    ULTK_WIDGET_TEXT,
    ULTK_WIDGET_TEXT_INPUT,
    ULTK_WIDGET_TEXT_INPUT_NUMERIC,
};

enum ultk_input_event_type {
    ULTK_INPUT_EVENT_QUIT,
    ULTK_INPUT_EVENT_KEY_PRESS,
    ULTK_INPUT_EVENT_KEY_RELEASE,
    ULTK_INPUT_EVENT_MOUSE_MOVEMENT,
    ULTK_INPUT_EVENT_MOUSE_BUTTON,
    ULTK_INPUT_EVENT_TOUCH,
    ULTK_INPUT_EVENT_CANVAS_RESIZE
};

union ultk_color_rgba {
    struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
    uint32_t rgba;
};

struct ultk_canvas {
    ultk_canvas_id_t id;
    struct {
        ultk_screen_coord_t x;
        ultk_screen_coord_t y;
    } size;
    ultk_widget_t *widget_top;
    ultk_input_state_t *input_state;
};

struct ultk_widget {
    ultk_widget_type_t type;
    //add stuff here
};

struct ultk_input_state {
    unsigned int num_events;
    ultk_input_event_t *events;
};

struct ultk_input_event {
    ultk_input_event_type_t event_type;
    //add stuff here
};

#endif