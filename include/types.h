#ifndef ULTK_TYPES_H
#define ULTK_TYPES_H

#include <stdint.h>

typedef int                        ultk_return_t;
typedef unsigned int               ultk_screen_coord_t;
typedef enum ultk_color_index      ultk_color_index_t;
typedef enum ultk_input_event_type ultk_input_event_type_t;
typedef union ultk_color_rgba      ultk_color_rgba_t;
typedef struct ultk_input_state    ultk_input_state_t;
typedef struct ultk_input_event    ultk_input_event_t;

enum ultk_color_index {
    ULTK_COLOR_BACKGROUND
};

enum ultk_input_event_type {
    ULTK_INPUT_EVENT_QUIT,
    ULTK_INPUT_EVENT_KEY_PRESS,
    ULTK_INPUT_EVENT_KEY_RELEASE,
    ULTK_INPUT_EVENT_MOUSE_MOVEMENT,
    ULTK_INPUT_EVENT_MOUSE_BUTTON
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

struct ultk_input_state {
    unsigned int num_events;
    ultk_input_event_t *events;
};

struct ultk_input_event {
    ultk_input_event_type_t event_type;
    //add stuff here
};

#endif