#include "w_button.h"
#include "uib_scalars.h"

ultk_return_t
ultk_uib_parse_w_button (
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
        &widget->button.label
    );

    uint8_t align_x_buffer;
    ultk_uib_parse_uint8(
        uib_text, 
        uib_text_len, 
        position,
        &align_x_buffer
    );
    widget->button.label_align_x = align_x_buffer;

    uint8_t align_y_buffer;
    ultk_uib_parse_uint8(
        uib_text, 
        uib_text_len, 
        position,
        &align_y_buffer
    );
    widget->button.label_align_y = align_y_buffer;

    ultk_uib_parse_uint16(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->button.size_min.x
    );

    ultk_uib_parse_uint16(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->button.size_min.y
    );

    ultk_uib_parse_uint16(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->button.size_max.x
    );

    ultk_uib_parse_uint16(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->button.size_max.y
    );

    ultk_uib_parse_string_after_len(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->button.callback_id_press
    );

    return ULTK_SUCCESS;
}
