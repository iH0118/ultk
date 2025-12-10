#include <stdlib.h>
#include "backend.h"

ultk_backend_sdl3_canvas_index_t *canvas_index;

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
