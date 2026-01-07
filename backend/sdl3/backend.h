#ifndef _ULTK_BACKEND_SDL3_H
#define _ULTK_BACKEND_SDL3_H

#include <SDL3/SDL.h>
#include <ultk/ultk_backend_api.h>

typedef struct ultk_backend_sdl3_canvas_index ultk_backend_sdl3_canvas_index_t;

extern ultk_backend_sdl3_canvas_index_t *canvas_index;

struct ultk_backend_sdl3_canvas_index {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Color color_fill;
};

#endif