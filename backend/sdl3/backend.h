#ifndef _ULTK_BACKEND_SDL3_H
#define _ULTK_BACKEND_SDL3_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <ultk/ultk_backend_api.h>

#define ULTK_BACKEND_SDL3_CANVAS_INDEX_INCREMENT (8)

typedef struct ultk_backend_sdl3_canvas  ultk_backend_sdl3_canvas_t;
typedef struct ultk_backend_sdl3_appdata ultk_backend_sdl3_appdata_t;

//extern ultk_backend_sdl3_canvas_index_t *canvas_index;

struct ultk_backend_sdl3_canvas {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color color_fill;
};

struct ultk_backend_sdl3_appdata {
    unsigned int num_canvas;
    unsigned int num_canvas_max;
    ultk_backend_sdl3_canvas_t *canvas;
};

#endif