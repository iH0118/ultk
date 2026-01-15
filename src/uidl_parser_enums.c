#include "uidl.h"

ultk_return_t
ultk_uidl_parse_canvas_type (
    char **token,
    ultk_canvas_type_t *type
)
{
    if (ultk_uidl_conditional_advance(token, "application"))
    {
        *type = ULTK_CANVAS_APPLICATION;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "utility"))
    {
        *type = ULTK_CANVAS_UTILITY;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "popup"))
    {
        *type = ULTK_CANVAS_POPUP_MENU;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "tooltip"))
    {
        *type = ULTK_CANVAS_TOOLTIP;
        return ULTK_SUCCESS;
    }

    return ULTK_ERROR_UIDL_SYNTAX;
}

ultk_return_t
ultk_uidl_parse_widget_type (
    char **token,
    ultk_widget_type_t *type
)
{
    if (ultk_uidl_conditional_advance(token, "array_static"))
    {
        *type = ULTK_WIDGET_ARRAY_STATIC;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "array_dynamic"))
    {
        *type = ULTK_WIDGET_ARRAY_DYNAMIC;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "button"))
    {
        *type = ULTK_WIDGET_BUTTON;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "checkbox"))
    {
        *type = ULTK_WIDGET_CHECKBOX;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "container"))
    {
        *type = ULTK_WIDGET_CONTAINER;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "container_label"))
    {
        *type = ULTK_WIDGET_CONTAINER_LABEL;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "container_split"))
    {
        *type = ULTK_WIDGET_CONTAINER_SPLIT;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "progressbar"))
    {
        *type = ULTK_WIDGET_PROGRESSBAR;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "radiobuttons"))
    {
        *type = ULTK_WIDGET_RADIOBUTTONS;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "text"))
    {
        *type = ULTK_WIDGET_TEXT;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "text_input"))
    {
        *type = ULTK_WIDGET_TEXT_INPUT;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "text_input_numeric"))
    {
        *type = ULTK_WIDGET_TEXT_INPUT_NUMERIC;
        return ULTK_SUCCESS;
    }

    return ULTK_ERROR_UIDL_SYNTAX;
}

ultk_return_t
ultk_uidl_parse_array_alignment (
    char **token,
    ultk_array_alignment_t *alignment
)
{
    if (ultk_uidl_conditional_advance(token, "left"))
    {
        *alignment = ULTK_ARRAY_ALIGN_LEFT;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "right"))
    {
        *alignment = ULTK_ARRAY_ALIGN_RIGHT;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "center"))
    {
        *alignment = ULTK_ARRAY_ALIGN_CENTER;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "fill"))
    {
        *alignment = ULTK_ARRAY_ALIGN_FILL;
        return ULTK_SUCCESS;
    }

    return ULTK_ERROR_UIDL_SYNTAX;
}
