#ifndef _ULTK_BACKEND_SDL3_H
#define _ULTK_BACKEND_SDL3_H

#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
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
    unsigned int num_canvas;
    ultk_backend_sdl3_canvas_t *canvas;
};

#endif