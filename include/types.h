#ifndef _ULTK_TYPES_H
#define _ULTK_TYPES_H

#include <stdint.h>

typedef int                             ultk_screen_coord_t;
typedef int                             ultk_canvas_id_t;
typedef int                             ultk_keycode_t;
typedef enum ultk_return                ultk_return_t;
typedef enum ultk_color_index           ultk_color_index_t;
typedef enum ultk_widget_type           ultk_widget_type_t;
typedef enum ultk_input_event_type      ultk_input_event_type_t;
typedef enum ultk_mouse_button          ultk_mouse_button_t;
typedef union ultk_color_rgba           ultk_color_rgba_t;
typedef struct ultk_canvas              ultk_canvas_t;
typedef struct ultk_widget              ultk_widget_t;
typedef struct ultk_input_queue         ultk_input_queue_t;
typedef struct ultk_input_event         ultk_input_event_t;
typedef struct ultk_event_keyboard      ultk_event_keyboard_t;
typedef struct ultk_event_mouse_motion  ultk_event_mouse_motion_t;
typedef struct ultk_event_mouse_button  ultk_event_mouse_button_t;
typedef struct ultk_event_mouse_scroll  ultk_event_mouse_scroll_t;
//typedef struct ultk_event_touch         ultk_event_touch_t;
typedef struct ultk_event_canvas_resize ultk_event_canvas_resize_t;
typedef struct ultk_event_canvas_quit   ultk_event_canvas_quit_t;

enum ultk_return {
    ULTK_SUCCESS                                   =  0x00,
    ULTK_BACKEND_INPUT_QUEUE_FULL                  =  0x1001,
    ULTK_ERROR_UNSPECIFIED                         = -0x01,
    ULTK_BACKEND_ERROR_UNSPECIFIED                 = -0x1001,
    ULTK_BACKEND_ERROR_INIT_ERROR                  = -0x1002,
    ULTK_BACKEND_ERROR_NOT_INITIALIZED             = -0x1003,
    ULTK_BACKEND_ERROR_MAX_CANVAS_COUNT_REACHED    = -0x1004,
    ULTK_BACKEND_ERROR_CANVAS_INDEX_OUT_OF_RANGE   = -0x1005,
    ULTK_BACKEND_ERROR_CANVAS_CREATION_ERROR       = -0x1006,
    ULTK_BACKEND_ERROR_CANVAS_DOESNT_EXIST         = -0x1007,
    ULTK_BACKEND_ERROR_INPUT_QUEUE_NOT_INITIALIZED = -0x1008,
    ULTK_BACKEND_ERROR_RENDER_ERROR                = -0x1009
};

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
    ULTK_WIDGET_ARRAY,
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
    ULTK_INPUT_EVENT_APPLICATION_QUIT,
    ULTK_INPUT_EVENT_KEYBOARD,
    ULTK_INPUT_EVENT_MOUSE_MOTION,
    ULTK_INPUT_EVENT_MOUSE_BUTTON,
    ULTK_INPUT_EVENT_MOUSE_SCROLL,
    //ULTK_INPUT_EVENT_TOUCH,
    ULTK_INPUT_EVENT_CANVAS_RESIZE,
    ULTK_INPUT_EVENT_CANVAS_QUIT
};

enum ultk_mouse_button {
    ULTK_MOUSE_BUTTON_LEFT,
    ULTK_MOUSE_BUTTON_MIDDLE,
    ULTK_MOUSE_BUTTON_RIGHT
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
};

struct ultk_widget {
    ultk_widget_type_t type;
    //add stuff here
};

struct ultk_event_keyboard {
    ultk_canvas_id_t canvas_id;
    ultk_keycode_t key;
    _Bool pressed;
    _Bool repeat;
};

struct ultk_event_mouse_motion {
    ultk_canvas_id_t canvas_id;
    ultk_screen_coord_t start_x;
    ultk_screen_coord_t start_y;
    ultk_screen_coord_t dist_x;
    ultk_screen_coord_t dist_y;
};

struct ultk_event_mouse_button {
    ultk_canvas_id_t canvas_id;
    ultk_screen_coord_t pos_x;
    ultk_screen_coord_t pos_y;
    ultk_mouse_button_t button;
    uint8_t num_clicks;
    _Bool pressed;
};

struct ultk_event_mouse_scroll {
    ultk_canvas_id_t canvas_id;
    ultk_screen_coord_t pos_x;
    ultk_screen_coord_t pos_y;
    ultk_screen_coord_t dist_x;
    ultk_screen_coord_t dist_y;
};

//struct ultk_event_touch {
//    ultk_canvas_id_t canvas_id;
//    ultk_screen_coord_t pos_x;
//    ultk_screen_coord_t pos_y;
//};

struct ultk_event_canvas_resize {
    ultk_canvas_id_t canvas_id;
    ultk_screen_coord_t size_x;
    ultk_screen_coord_t size_y;
};

struct ultk_event_canvas_quit {
    ultk_canvas_id_t canvas_id;
};

struct ultk_input_event {
    ultk_input_event_type_t event_type;
    union {
        ultk_event_keyboard_t keyboard;
        ultk_event_mouse_motion_t mouse_motion;
        ultk_event_mouse_button_t mouse_button;
        ultk_event_mouse_scroll_t mouse_scroll;
        //ultk_event_touch_t touch;
        ultk_event_canvas_resize_t canvas_resize;
        ultk_event_canvas_quit_t canvas_quit;
    };
};

struct ultk_input_queue {
    unsigned int num_events;
    ultk_input_event_t *events;
};

#endif