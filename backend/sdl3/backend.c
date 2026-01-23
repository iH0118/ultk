#include <stdlib.h>
#include "backend.h"
#include "ultk/ultk_backend_api.h"

SDL_AppResult
SDL_AppInit (
    void **appstate,
    int argc,
    char **argv
)
{
    *appstate = malloc(sizeof(ultk_backend_sdl3_appdata_t));

    if (!*appstate)
    {
        return SDL_APP_FAILURE;
    }

    ultk_return_t status = ultk_backend_callback_init(
        &(*(ultk_backend_sdl3_appdata_t **)appstate)->application,
        *appstate,
        argc,
        argv
    );
    
    if (status != ULTK_SUCCESS)
    {
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppIterate (
    void *appstate
)
{
    ultk_backend_callback_frame(
        ((ultk_backend_sdl3_appdata_t *)appstate)->application,
        appstate
    );
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
