#ifndef _ULTK_CANVAS_H_INTERNAL
#define _ULTK_CANVAS_H_INTERNAL

#include <ultk/ultk_common.h>
#include <ultk/ultk_canvas.h>

ultk_return_t
ultk_create_canvas_uib (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    ultk_canvas_t *canvas
);

#endif