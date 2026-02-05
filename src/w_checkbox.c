#include "w_checkbox.h"
#include "uib_scalars.h"

ultk_return_t
ultk_uib_parse_w_checkbox (
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
        &widget->checkbox.label
    );

    ultk_uib_parse_bool(
        uib_text,
        uib_text_len,
        position,
        &widget->checkbox.checked
    );

    ultk_uib_parse_string_after_len(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->checkbox.callback_id_check
    );

    ultk_uib_parse_string_after_len(
        uib_text, 
        uib_text_len, 
        position, 
        &widget->checkbox.callback_id_uncheck
    );

    return ULTK_SUCCESS;
}
