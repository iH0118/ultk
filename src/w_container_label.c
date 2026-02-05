#include <stdlib.h>
#include "w_container_label.h"
#include "uib_scalars.h"
#include "widget.h"

ultk_return_t
ultk_uib_parse_w_container_label (
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

    ultk_uib_parse_string_after_len(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->container_label.label
    );

    uint8_t label_align_buffer;
    ultk_uib_parse_uint8(
        uib_text,
        uib_text_len,
        position,
        &label_align_buffer
    );
    widget->container_label.label_align = label_align_buffer;

    ultk_uib_parse_bool(
        uib_text,
        uib_text_len,
        position,
        &widget->container_label.border
    );

    widget->container_label.child = malloc(sizeof(ultk_widget_t));

    return ultk_create_widget_uib(
        uib_text, 
        uib_text_len, 
        position, 
        widget->container_label.child
    );

}
