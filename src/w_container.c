#include <stdlib.h>
#include "w_container.h"
#include "uib_scalars.h"
#include "widget.h"

ultk_return_t
ultk_uib_parse_w_container (
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

    ultk_uib_parse_float(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_relative.l
    );

    ultk_uib_parse_float(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_relative.r
    );

    ultk_uib_parse_float(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_relative.t
    );

    ultk_uib_parse_float(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_relative.b
    );

    ultk_uib_parse_uint16(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_absolute.l
    );

    ultk_uib_parse_uint16(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_absolute.r
    );

    ultk_uib_parse_uint16(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_absolute.t
    );

    ultk_uib_parse_uint16(
        uib_text,
        uib_text_len,
        position,
        &widget->container.padding_absolute.b
    );

    widget->container.child = malloc(sizeof(ultk_widget_t));

    return ultk_create_widget_uib(
        uib_text, 
        uib_text_len, 
        position, 
        widget->container.child
    );
}
