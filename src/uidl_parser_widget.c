#include "uidl.h"
#include "alloc.h"
#include "ultk/ultk_common.h"
#include "ultk/ultk_widget.h"
#include <string.h>

ultk_return_t
ultk_uidl_parse_field_array_static (
    char **token,
    ultk_widget_t *widget
)
{
    if (ultk_uidl_cond_adv_col(token, "num_rows"))
    {
        return ultk_uidl_parse_int(token, &widget->array_static.num_rows);
    }

    if (ultk_uidl_cond_adv_col(token, "num_cols"))
    {
        return ultk_uidl_parse_int(token, &widget->array_static.num_cols);
    }

    if (ultk_uidl_cond_adv_col(token, "alignment"))
    {
        return ultk_uidl_parse_array_alignment(token, &widget->array_static.alignment);
    }

    if (ultk_uidl_cond_adv_col(token, "scrollable_x"))
    {
        return ultk_uidl_parse_bool(token, &widget->array_static.scrollable_x);
    }

    if (ultk_uidl_cond_adv_col(token, "scrollable_y"))
    {
        return ultk_uidl_parse_bool(token, &widget->array_static.scrollable_y);
    }

    if (ultk_uidl_cond_adv_col(token, "w_children"))
    {
        //aaaAAAAAA
    }

    return ULTK_ERROR_UIDL_SYNTAX;
}

ultk_return_t
ultk_uidl_parse_widget (
    char **token,
    ultk_widget_t **widget
)
{
    ultk_return_t status;

    if (!ultk_uidl_conditional_advance(token, "{"))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    status = ultk_alloc_widget(widget);

    if (status != ULTK_SUCCESS)
    {
        return status;
    }

    (*widget)->type = ULTK_WIDGET_NULL;
    (*widget)->id = NULL;

    if (ultk_uidl_conditional_advance(token, "}"))
    {
        (*widget)->type = ULTK_WIDGET_VOID;
        return ULTK_SUCCESS;
    }

    while (1)
    {
        if (ultk_uidl_cond_adv_col(token, "type"))
        {
            status = ultk_uidl_parse_widget_type(token, &(*widget)->type);
        }

        if (ultk_uidl_cond_adv_col(token, "id"))
        {
            status = ultk_uidl_parse_string(token, &(*widget)->id);
        }

        switch ((*widget)->type)
        {
            case ULTK_WIDGET_ARRAY_STATIC:
            status = ultk_uidl_parse_field_array_static(token, *widget);
            break;
        }

        //parse fields


        if (status != ULTK_SUCCESS)
        {
            return status;
        }

        if (ultk_uidl_conditional_advance(token, ","))
        {
            continue;
        }

        if (ultk_uidl_conditional_advance(token, "}"))
        {
            break;
        }

        return ULTK_ERROR_UIDL_SYNTAX;
    }

    if ((*widget)->type == ULTK_WIDGET_NULL || !(*widget)->id)
    {
        return ULTK_ERROR_UIDL_MISSING_FIELD;
    }

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uidl_parse_widget_array (
    char **token,
    ultk_widget_t **widget,
    int *num_widgets
)
{
    ultk_return_t status;

    if (!ultk_uidl_conditional_advance(token, "["))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    
}