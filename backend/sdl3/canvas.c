
#include <stdlib.h>
#include "backend.h"

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
)
{
    ultk_backend_sdl3_appdata_t *appdata = backend_state;

    if (appdata->num_canvas <= canvas_id)
    {
        appdata->num_canvas = canvas_id + 1;
        appdata->canvas = realloc(
            appdata->canvas,
            appdata->num_canvas * sizeof(ultk_backend_sdl3_canvas_t)
        );

        if (appdata->canvas == NULL)
        {
            return ULTK_BACKEND_ERROR_ALLOCATION_FAILED;
        }

        appdata->canvas[canvas_id].exists = 0;
    }

    if (appdata->canvas[canvas_id].exists)
    {
        return ULTK_BACKEND_ERROR_CANVAS_ALREADY_EXISTS;
    }

    if (!SDL_CreateWindowAndRenderer(
            title,
            requested_size_x,
            requested_size_y,
            0,
            &appdata->canvas[canvas_id].window,
            &appdata->canvas[canvas_id].renderer
        ))
    {
        return ULTK_BACKEND_ERROR_COULDNT_CREATE_CANVAS;
    }

    appdata->canvas[canvas_id].exists = 1;

    SDL_GetWindowSize(
        appdata->canvas[canvas_id].window,
        canvas_size_x,
        canvas_size_y
    );

    appdata->canvas[canvas_id].color_fill.r = color_fill_rgba.r;
    appdata->canvas[canvas_id].color_fill.g = color_fill_rgba.g;
    appdata->canvas[canvas_id].color_fill.b = color_fill_rgba.b;
    appdata->canvas[canvas_id].color_fill.a = color_fill_rgba.a;

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_backend_destroy_canvas (
    void *backend_state,
    ultk_canvas_numid_t canvas_id
)
{
    ultk_backend_sdl3_appdata_t *appdata = backend_state;

    if (appdata->num_canvas <= canvas_id)
    {
        return ULTK_BACKEND_ERROR_CANVAS_DOESNT_EXIST;
    }

    if (!appdata->canvas[canvas_id].exists)
    {
        return ULTK_BACKEND_ERROR_CANVAS_DOESNT_EXIST;
    }

    SDL_DestroyRenderer(appdata->canvas[canvas_id].renderer);
    SDL_DestroyWindow(appdata->canvas[canvas_id].window);

    appdata->canvas[canvas_id].exists = 0;

    return ULTK_SUCCESS;
}

/*
ultk_return_t
ultk_backend_clear_canvas (
    void *backend_state,
    ultk_canvas_numid_t canvas_id
)
{
    return ULTK_SUCCESS;
}
*/
