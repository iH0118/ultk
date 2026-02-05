#include <stdlib.h>
#include "w_array_dynamic.h"
#include "uib_scalars.h"
#include "widget.h"

ultk_return_t
ultk_uib_parse_w_array_dynamic (
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

    uint8_t alignment_buffer;
    ultk_uib_parse_uint8(
        uib_text, 
        uib_text_len, 
        position,
        &alignment_buffer
    );
    widget->array_dynamic.alignment = alignment_buffer;

    ultk_uib_parse_bool(
        uib_text, 
        uib_text_len, 
        position,
        &widget->array_dynamic.keep_grid
    );

    uint8_t reflow_dir_buffer;
    ultk_uib_parse_uint8(
        uib_text,
        uib_text_len,
        position,
        &reflow_dir_buffer
    );
    widget->array_dynamic.reflow_direction = reflow_dir_buffer;

    ultk_uib_parse_uint8(
        uib_text,
        uib_text_len,
        position,
        &widget->array_dynamic.max_reflow_sections
    );

    ultk_uib_parse_uint16(
        uib_text, 
        uib_text_len, 
        position,
        &widget->array_dynamic.num_children
    );

    widget->array_dynamic.children = 
        malloc(widget->array_dynamic.num_children * sizeof(ultk_widget_t));

    ultk_return_t status;

    uint16_t i;
    for (i = 0; i < widget->array_dynamic.num_children; i++)
    {
        status = ultk_create_widget_uib(
            uib_text,
            uib_text_len,
            position,
            widget->array_dynamic.children
        );

        if (status != ULTK_SUCCESS)
        {
            return status;
        }
    }

    return ULTK_SUCCESS;
}
