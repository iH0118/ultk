#ifndef ULTK_TYPES_H
#define ULTK_TYPES_H

#include <stdint.h>

typedef int ultk_backend_return;
typedef int ultk_screen_coord;
typedef enum {
    ULTK_COLOR_BACKGROUND
} ultk_color_index;
typedef union {
    struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
    uint32_t rgba;
} ultk_color_rgb;

#endif