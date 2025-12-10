#include "backend.h"

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
)
{
    if (!canvas_index) return ULTK_BACKEND_ERROR_NOT_INITIALIZED;

    int i;
    for (i = 0; i < _ULTK_BACKEND_MAX_CANVAS_COUNT; i++)
    {
        if (canvas_index[i].window) continue;

        if (!SDL_CreateWindowAndRenderer(
                title,
                requested_size_x,
                requested_size_y,
                0,
                &(canvas_index[i].window),
                &(canvas_index[i].renderer)
            )
        ) 
        {
            return ULTK_BACKEND_ERROR_CANVAS_CREATION_ERROR;
        }

        SDL_GetWindowSize(canvas_index[i].window, canvas_size_x, canvas_size_y);

        canvas_index[i].color_fill.r = color_fill_rgba.r;
        canvas_index[i].color_fill.g = color_fill_rgba.g;
        canvas_index[i].color_fill.b = color_fill_rgba.b;
        canvas_index[i].color_fill.a = color_fill_rgba.a;

        *canvas_id = i;

        return ULTK_SUCCESS;
    }

    return ULTK_BACKEND_ERROR_MAX_CANVAS_COUNT_REACHED;
}

ultk_return_t
ultk_backend_destroy_canvas (
    ultk_canvas_id_t canvas_id
)
{
    if (canvas_id >= _ULTK_BACKEND_MAX_CANVAS_COUNT)
    {
        return ULTK_BACKEND_ERROR_CANVAS_INDEX_OUT_OF_RANGE;
    }

    if (!canvas_index[canvas_id].window)
    {
        return ULTK_BACKEND_ERROR_CANVAS_DOESNT_EXIST;
    }

    SDL_DestroyRenderer(canvas_index[canvas_id].renderer);
    SDL_DestroyWindow(canvas_index[canvas_id].window);

    return ULTK_SUCCESS;
}