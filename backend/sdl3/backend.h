#ifndef _ULTK_BACKEND_SDL3_H
#define _ULTK_BACKEND_SDL3_H

#include <SDL3/SDL.h>
#include <ultk/ultk_backend_api.h>

typedef struct ultk_backend_sdl3_canvas  ultk_backend_sdl3_canvas_t;
typedef struct ultk_backend_sdl3_appdata ultk_backend_sdl3_appdata_t;

struct ultk_backend_sdl3_canvas {
    _Bool exists;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color color_fill;
};

struct ultk_backend_sdl3_appdata {
    ultk_application_t *application;
    void *application_data;
    unsigned int num_canvas;
    ultk_backend_sdl3_canvas_t *canvas;
};

#endif