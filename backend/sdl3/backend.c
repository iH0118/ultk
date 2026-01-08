#include <stdlib.h>
#include "backend.h"

//ultk_backend_sdl3_canvas_index_t *canvas_index;

SDL_AppResult
SDL_AppInit (
    void **appstate,
    int argc,
    char **argv
)
{
}

SDL_AppResult
SDL_AppIterate (
    void *appstate
)
{
}

SDL_AppResult
SDL_AppEvent (
    void *appstate,
    SDL_Event *event
)
{
}

void
SDL_AppQuit (
    void *appstate,
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
