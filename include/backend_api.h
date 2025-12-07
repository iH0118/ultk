#ifndef ULTK_BACKEND_API_H
#define ULTK_BACKEND_API_H

#include <types.h>

ultk_backend_return
ultk_backend_draw_pixel (
    ultk_screen_coord x,
    ultk_screen_coord y,
    ultk_color_index  color_index,
    ultk_color_rgb    color_rgb
);


ultk_backend_return
ultk_backend_draw_line (
    ultk_screen_coord start_x,
    ultk_screen_coord start_y,
    ultk_screen_coord end_x,
    ultk_screen_coord end_y,
    ultk_color_index  color_index,
    ultk_color_rgb    color_rgb
);

#endif