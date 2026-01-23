#include <stdlib.h>
#include "uib_w_array_static.h"
#include "uib_scalars.h"
#include "uib_widget.h"

ultk_return_t
ultk_uib_parse_w_array_static (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    ultk_widget_t *widget
)
{
    ultk_uib_parse_string_after_len(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->id
    );

    ultk_uib_parse_uint8(
        uib_text, 
        uib_text_len, 
        position,
        &widget->array_static.num_rows
    );

    ultk_uib_parse_uint8(
        uib_text, 
        uib_text_len, 
        position,
        &widget->array_static.num_cols
    );

    uint8_t alignment_buffer;
    ultk_uib_parse_uint8(
        uib_text, 
        uib_text_len, 
        position,
        &alignment_buffer
    );
    widget->array_static.alignment = alignment_buffer;

    ultk_uib_parse_bool(
        uib_text, 
        uib_text_len, 
        position,
        &widget->array_static.scrollable_x
    );

    ultk_uib_parse_bool(
        uib_text, 
        uib_text_len, 
        position,
        &widget->array_static.scrollable_y
    );

    ultk_uib_parse_uint16(
        uib_text, 
        uib_text_len, 
        position,
        &widget->array_static.num_children
    );

    widget->array_static.children = 
        malloc(widget->array_static.num_children * sizeof(ultk_widget_t));

    ultk_return_t status;

    for (int i = 0; i < widget->array_static.num_children; i++)
    {
        status = ultk_uib_parse_widget(
            uib_text,
            uib_text_len,
            position,
            widget->array_static.children
        );

        if (status != ULTK_SUCCESS)
        {
            return status;
        }
    }

    return ULTK_SUCCESS;
}
