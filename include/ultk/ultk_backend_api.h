#ifndef _ULTK_BACKEND_API_H
#define _ULTK_BACKEND_API_H

#include <ultk/ultk.h>

/* FUNCTIONS PROVIDED BY FRONTEND */

ultk_return_t
ultk_backend_callback_init (
    ultk_application_t **application,
    void **application_data,
    void *backend_state,
    int argc,
    char **argv
);

ultk_return_t
ultk_backend_callback_frame (
    ultk_application_t *application,
    void *application_data,
    void *backend_state
);

ultk_return_t
ultk_backend_callback_event (
    ultk_application_t *application,
    void *application_data,
    void *backend_state
);

ultk_return_t
ultk_backend_callback_quit (
    ultk_application_t *application,
    void *application_data,
    void *backend_state
);

/* FUNCTIONS PROVIDED BY BACKEND */

ultk_return_t
ultk_backend_create_canvas (
    void *backend_state,
    ultk_canvas_numid_t canvas_id,
    char *title,
    ultk_screen_coord_t requested_size_x,
    ultk_screen_coord_t requested_size_y,
    ultk_screen_coord_t *canvas_size_x,
    ultk_screen_coord_t *canvas_size_y,
    ultk_color_index_t color_fill_index,
    ultk_color_rgba_t color_fill_rgba
);

ultk_return_t
ultk_backend_destroy_canvas (
    void *backend_state,
    ultk_canvas_numid_t canvas_id
);

ultk_return_t
ultk_backend_draw_pixel (
    void *backend_state,
    ultk_canvas_numid_t canvas_id,
    ultk_screen_coord_t x,
    ultk_screen_coord_t y,
    ultk_color_index_t color_index,
    ultk_color_rgba_t color_rgba
);

ultk_return_t
ultk_backend_draw_line (
    void *backend_state,
    ultk_canvas_numid_t canvas_id,
    ultk_screen_coord_t start_x,
    ultk_screen_coord_t start_y,
    ultk_screen_coord_t end_x,
    ultk_screen_coord_t end_y,
    ultk_color_index_t color_index,
    ultk_color_rgba_t color_rgba
);

#endif