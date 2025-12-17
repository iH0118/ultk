#include "backend.h"

ultk_return_t
ultk_backend_draw_pixel (
    ultk_canvas_id_t    canvas_id,
    ultk_screen_coord_t x,
    ultk_screen_coord_t y,
    ultk_color_index_t  color_index,
    ultk_color_rgba_t   color_rgba
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

    if (!SDL_SetRenderDrawColor(
            canvas_index[canvas_id].renderer,
            color_rgba.r,
            color_rgba.g,
            color_rgba.b,
            color_rgba.a
        ) ||
        !SDL_RenderPoint(canvas_index[canvas_id].renderer, x, y)
    )
    {
        return ULTK_BACKEND_ERROR_RENDER_ERROR;
    }

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_backend_draw_line (
    ultk_canvas_id_t    canvas_id,
    ultk_screen_coord_t start_x,
    ultk_screen_coord_t start_y,
    ultk_screen_coord_t end_x,
    ultk_screen_coord_t end_y,
    ultk_color_index_t  color_index,
    ultk_color_rgba_t   color_rgba
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

    if (!SDL_SetRenderDrawColor(
            canvas_index[canvas_id].renderer,
            color_rgba.r,
            color_rgba.g,
            color_rgba.b,
            color_rgba.a
        ) ||
        !SDL_RenderLine(
            canvas_index[canvas_id].renderer,
            start_x, 
            start_y, 
            end_x, 
            end_y
        )
    )
    {
        return ULTK_BACKEND_ERROR_RENDER_ERROR;
    }

    return ULTK_SUCCESS;
}