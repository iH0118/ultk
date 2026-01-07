#ifndef _ULTK_INPUT_H
#define _ULTK_INPUT_H

#include <ultk/ultk_common.h>
#include <ultk/ultk_canvas.h>

typedef int                             ultk_keycode_t;
typedef enum ultk_input_event_type      ultk_input_event_type_t;
typedef enum ultk_mouse_button          ultk_mouse_button_t;
typedef struct ultk_input_queue         ultk_input_queue_t;
typedef struct ultk_input_event         ultk_input_event_t;
typedef struct ultk_event_keyboard      ultk_event_keyboard_t;
typedef struct ultk_event_mouse_motion  ultk_event_mouse_motion_t;
typedef struct ultk_event_mouse_button  ultk_event_mouse_button_t;
typedef struct ultk_event_mouse_scroll  ultk_event_mouse_scroll_t;
//typedef struct ultk_event_touch         ultk_event_touch_t;
typedef struct ultk_event_canvas_resize ultk_event_canvas_resize_t;
typedef struct ultk_event_canvas_quit   ultk_event_canvas_quit_t;

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