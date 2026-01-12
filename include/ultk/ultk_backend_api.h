#ifndef _ULTK_BACKEND_API_H
#define _ULTK_BACKEND_API_H

#include <ultk/ultk.h>

#define _ULTK_BACKEND_MAX_CANVAS_COUNT (16)
#define _ULTK_BACKEND_EVENT_QUEUE_LENGTH (64)

ultk_return_t
ultk_backend_initialize ();

ultk_return_t
ultk_backend_exit ();

ultk_return_t
ultk_backend_create_canvas (
    ultk_canvas_id_t     *canvas_id,
    ultk_screen_coord_t   requested_size_x,
    ultk_screen_coord_t   requested_size_y,
    ultk_screen_coord_t  *canvas_size_x,
    ultk_screen_coord_t  *canvas_size_y,
    ultk_color_index_t    color_fill_index,
    ultk_color_rgba_t     color_fill_rgba,
    char                 *title
);

ultk_return_t
ultk_backend_destroy_canvas (
    ultk_canvas_id_t canvas_id
);

ultk_return_t
ultk_backend_clear_canvas (
    ultk_canvas_id_t canvas_id
);

ultk_return_t
ultk_backend_draw_pixel (
    ultk_canvas_id_t    canvas_id,
    ultk_screen_coord_t x,
    ultk_screen_coord_t y,
    ultk_color_index_t  color_index,
    ultk_color_rgba_t   color_rgba
);

ultk_return_t
ultk_backend_draw_line (
    ultk_canvas_id_t    canvas_id,
    ultk_screen_coord_t start_x,
    ultk_screen_coord_t start_y,
    ultk_screen_coord_t end_x,
    ultk_screen_coord_t end_y,
    ultk_color_index_t  color_index,
    ultk_color_rgba_t   color_rgba
);

/*
ultk_return_t
ultk_backend_query_input (
    ultk_input_queue_t *input_queue
);
*/

#endif