#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <stdlib.h>
#include "backend.h"

SDL_AppResult
SDL_AppInit (
    void **appstate,
    int argc,
    char **argv
)
{
    *appstate = malloc(sizeof(ultk_backend_sdl3_appdata_t));
    (*(ultk_backend_sdl3_appdata_t **)appstate)->num_canvas = 0;

    if (!*appstate)
    {
        return SDL_APP_FAILURE;
    }

    ultk_return_t status = ultk_backend_callback_init(
        &(*(ultk_backend_sdl3_appdata_t **)appstate)->application,
        &(*(ultk_backend_sdl3_appdata_t **)appstate)->application_data,
        *appstate,
        argc,
        argv
    );

    switch (status)
    {
        case ULTK_SUCCESS:
        case ULTK_EXIT_CALLBACK_SUCCESS:
        return SDL_APP_SUCCESS;
        break;

        case ULTK_CONTINUE:
        return SDL_APP_CONTINUE;
        break;

        default:
        break;
    }

    return SDL_APP_FAILURE;
}

SDL_AppResult
SDL_AppIterate (
    void *appstate
)
{
    ultk_backend_callback_frame(
        ((ultk_backend_sdl3_appdata_t *)appstate)->application,
        ((ultk_backend_sdl3_appdata_t *)appstate)->application_data,
        appstate
    );

    return SDL_APP_CONTINUE;
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
    ultk_backend_callback_quit(
        ((ultk_backend_sdl3_appdata_t *)appstate)->application,
        ((ultk_backend_sdl3_appdata_t *)appstate)->application_data,
        appstate
    );

    unsigned int i;
    for (i = 0; i < ((ultk_backend_sdl3_appdata_t *)appstate)->num_canvas; i++)
    {
        ultk_backend_destroy_canvas(appstate, i);
    }

    free(((ultk_backend_sdl3_appdata_t *)appstate)->canvas);
    free(appstate);
}
