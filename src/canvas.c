#include <stdlib.h>
#include "uib_scalars.h"
#include "widget.h"
#include "canvas.h"

ultk_return_t
ultk_create_canvas_uib (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    ultk_canvas_t *canvas
)
{
    unsigned int initial_position = *position;

    uint32_t canvas_size;
    if (ultk_uib_parse_uint32(
            uib_text,
            uib_text_len,
            position,
            &canvas_size
        ) != ULTK_SUCCESS ||
        *position + canvas_size > uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    uint8_t canvas_type_buffer;
    ultk_uib_parse_uint8(
        uib_text,
        uib_text_len,
        position,
        &canvas_type_buffer
    );
    canvas->type = canvas_type_buffer;

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        position,
        &canvas->id
    );

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        position,
        &canvas->title
    );

    ultk_uib_parse_uint16(
        uib_text,
        uib_text_len,
        position,
        &canvas->size.x
    );

    ultk_uib_parse_uint16(
        uib_text,
        uib_text_len,
        position,
        &canvas->size.y
    );

    canvas->widget_top = malloc (sizeof(ultk_widget_t));

    ultk_create_widget_uib(
        uib_text,
        uib_text_len,
        position,
        canvas->widget_top
    );

    if (*position - initial_position != canvas_size)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    return ULTK_SUCCESS;
}
