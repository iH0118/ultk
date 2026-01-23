#include "uib_scalars.h"
#include "widget.h"
#include "w_array_static.h"
#include "w_array_dynamic.h"
#include "w_button.h"
#include "w_checkbox.h"
#include "w_container.h"
#include "w_container_label.h"


ultk_return_t
ultk_create_widget_uib (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    ultk_widget_t *widget
)
{
    unsigned int initial_position = *position;

    uint32_t widget_size;
    if (ultk_uib_parse_uint32(
            uib_text,
            uib_text_len,
            position,
            &widget_size
        ) != ULTK_SUCCESS ||
        *position + widget_size > uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    uint8_t widget_type_buffer;
    ultk_uib_parse_uint8(
        uib_text,
        uib_text_len,
        position,
        &widget_type_buffer
    );
    widget->type = widget_type_buffer;

    ultk_return_t status;

    switch (widget->type)
    {
        case ULTK_WIDGET_VOID:
        break;

        case ULTK_WIDGET_ARRAY_STATIC:
        status = ultk_uib_parse_w_array_static(
            uib_text, 
            uib_text_len, 
            position, 
            widget
        );
        break;

        case ULTK_WIDGET_ARRAY_DYNAMIC:
        status = ultk_uib_parse_w_array_dynamic(
            uib_text, 
            uib_text_len, 
            position, 
            widget
        );
        break;

        case ULTK_WIDGET_BUTTON:
        status = ultk_uib_parse_w_button(
            uib_text, 
            uib_text_len, 
            position, 
            widget
        );
        break;

        case ULTK_WIDGET_CHECKBOX:
        status = ultk_uib_parse_w_checkbox(
            uib_text, 
            uib_text_len, 
            position, 
            widget
        );
        break;

        case ULTK_WIDGET_CONTAINER:
        status = ultk_uib_parse_w_container(
            uib_text, 
            uib_text_len, 
            position, 
            widget
        );
        break;

        case ULTK_WIDGET_CONTAINER_LABEL:
        status = ultk_uib_parse_w_container_label(
            uib_text, 
            uib_text_len, 
            position, 
            widget
        );
        break;

        default:
        return ULTK_ERROR_UIB_ERROR;
    }

    if (status != ULTK_SUCCESS)
    {
        return status;
    }

    if (*position - initial_position != widget_size)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    return ULTK_SUCCESS;
}
