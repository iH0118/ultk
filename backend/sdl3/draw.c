#include "backend.h"

ultk_return_t
ultk_backend_draw_pixel (
    void *backend_state,
    ultk_canvas_numid_t canvas_id,
    ultk_screen_coord_t x,
    ultk_screen_coord_t y,
    ultk_color_index_t color_index,
    ultk_color_rgba_t color_rgba
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

    if (!SDL_SetRenderDrawColor(
            appdata->canvas[canvas_id].renderer,
            color_rgba.r, 
            color_rgba.g, 
            color_rgba.b, 
            color_rgba.a
        ) || !SDL_RenderPoint(
            appdata->canvas[canvas_id].renderer, 
            x, 
            y
        )
    )
    {
        return ULTK_BACKEND_ERROR_RENDER_ERROR;
    }

    return ULTK_SUCCESS;
}

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

    if (!SDL_SetRenderDrawColor(
            appdata->canvas[canvas_id].renderer,
            color_rgba.r,
            color_rgba.g,
            color_rgba.b,
            color_rgba.a
        ) || !SDL_RenderLine(
            appdata->canvas[canvas_id].renderer, 
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