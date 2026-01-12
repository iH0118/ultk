#include <stdlib.h>
#include "backend.h"

//ultk_backend_sdl3_canvas_index_t *canvas_index;

SDL_AppResult
SDL_AppInit (
    ultk_backend_sdl3_appdata_t **appstate,
    int argc,
    char **argv
)
{
    *appstate = malloc(sizeof(ultk_backend_sdl3_appdata_t));

    if (!*appstate)
    {
        return SDL_APP_FAILURE;
    }

    (*appstate)->num_canvas_max = ULTK_BACKEND_SDL3_CANVAS_INDEX_INCREMENT;    
}

SDL_AppResult
SDL_AppIterate (
    ultk_backend_sdl3_appdata_t *appstate
)
{
}

SDL_AppResult
SDL_AppEvent (
    ultk_backend_sdl3_appdata_t *appstate,
    SDL_Event *event
)
{
}

void
SDL_AppQuit (
    ultk_backend_sdl3_appdata_t *appstate,
    SDL_AppResult result
)
{
}
/*
ultk_return_t
ultk_backend_initialize ()
{
    if ((
        canvas_index = calloc(
            _ULTK_BACKEND_MAX_CANVAS_COUNT,
            sizeof(ultk_backend_sdl3_canvas_index_t) 
        )
    ))
    {
        return ULTK_SUCCESS;
    }
    
    return ULTK_BACKEND_ERROR_INIT_ERROR;
}

ultk_return_t
ultk_backend_exit ()
{
    free(canvas_index);
    return ULTK_SUCCESS;
}
*/
