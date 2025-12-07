#ifndef ULTK_BACKEND_API_H
#define ULTK_BACKEND_API_H

#include <types.h>

ultk_backend_return_t
ultk_backend_draw_pixel (
    ultk_screen_coord_t x,
    ultk_screen_coord_t y,
    ultk_color_index_t  color_index,
    ultk_color_rgb_t    color_rgb
);

ultk_backend_return_t
ultk_backend_draw_line (
    ultk_screen_coord_t start_x,
    ultk_screen_coord_t start_y,
    ultk_screen_coord_t end_x,
    ultk_screen_coord_t end_y,
    ultk_color_index_t  color_index,
    ultk_color_rgb_t    color_rgb
);

ultk_backend_return_t
ultk_backend_get_input (
    ultk_input_state_t *input_state
);

#endif