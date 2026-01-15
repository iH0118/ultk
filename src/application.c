#include "application.h"
#include "uidl.h"
#include "alloc.h"
#include <stdlib.h>
#include <string.h>

ultk_return_t
ultk_uidl_parse_metadata (
    char **token,
    ultk_application_metadata_t **metadata
)
{
    ultk_return_t status;

    if (!ultk_uidl_conditional_advance(token, "{"))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    status = ultk_alloc_application_metadata(metadata);

    if (status != ULTK_SUCCESS)
    {
        return status;
    }

    while (1)
    {
        if (ultk_uidl_cond_adv_col(token, "name"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->name);
        }

        if (ultk_uidl_cond_adv_col(token, "version"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->version);
        }

        if (ultk_uidl_cond_adv_col(token, "id"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->id);
        }

        if (ultk_uidl_cond_adv_col(token, "creator"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->creator);
        }

        if (ultk_uidl_cond_adv_col(token, "copyright"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->copyright);
        }

        if (ultk_uidl_cond_adv_col(token, "url"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->url);
        }

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

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uidl_parse_canvas_array (
    char **token,
    ultk_canvas_t **canvas,
    unsigned int *num_canvas
)
{
    ultk_return_t status;
    int current_canvas = -1;

    if (!ultk_uidl_conditional_advance(token, "["))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    while (1)
    {
        if (!ultk_uidl_conditional_advance(token, "{"))
        {
            return ULTK_ERROR_UIDL_SYNTAX;
        }

        status = ultk_alloc_canvas_array(canvas, num_canvas);

        if (status != ULTK_SUCCESS)
        {
            return status;
        }

        (*canvas)->type = ULTK_CANVAS_NULL;
        (*canvas)->id = NULL;
        (*canvas)->title = NULL;
        (*canvas)->size.x = 0;
        (*canvas)->size.y = 0;
        (*canvas)->widget_top = NULL;

        current_canvas += 1;

        while (1)
        {
            if (ultk_uidl_cond_adv_col(token, "type"))
            {
                status = ultk_uidl_parse_canvas_type(token, &(*canvas)[current_canvas].type);
            }

            if (ultk_uidl_cond_adv_col(token, "id"))
            {
                status = ultk_uidl_parse_string(token, &(*canvas)[current_canvas].id);
            }

            if (ultk_uidl_cond_adv_col(token, "title"))
            {
                status = ultk_uidl_parse_string(token, &(*canvas)[current_canvas].title);
            }

            if (ultk_uidl_cond_adv_col(token, "dims"))
            {
                if (!ultk_uidl_conditional_advance(token, "{"))
                {
                    return ULTK_ERROR_UIDL_SYNTAX;
                }

                while (1)
                {
                    if (ultk_uidl_cond_adv_col(token, "x"))
                    {
                        status = ultk_uidl_parse_int(token, &(*canvas)->size.x);
                    }

                    if (ultk_uidl_cond_adv_col(token, "y"))
                    {
                        status = ultk_uidl_parse_int(token, &(*canvas)->size.y);
                    }

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
            }

            if (ultk_uidl_cond_adv_col(token, "w_top"))
            {
                status = ultk_uidl_parse_widget(token, &(*canvas)->widget_top);
            }

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

        if ((*canvas)->type == ULTK_CANVAS_NULL || !(*canvas)->id)
        {
            return ULTK_ERROR_UIDL_MISSING_FIELD;
        }

        if (ultk_uidl_conditional_advance(token, ","))
        {
            continue;
        }

        if (ultk_uidl_conditional_advance(token, "]"))
        {
            break;
        }

        return ULTK_ERROR_UIDL_SYNTAX;
    }

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uidl_parse_application (
    char **token,
    ultk_application_t *application
)
{
    ultk_return_t status;

    if (!ultk_uidl_conditional_advance(token, "{"))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    while (1)
    {
        if (ultk_uidl_cond_adv_col(token, "metadata"))
        {
            status = ultk_uidl_parse_metadata(token, &application->metadata);
        }

        if (ultk_uidl_cond_adv_col(token, "canvas"))
        {
            status = ultk_uidl_parse_canvas_array(token, &application->canvas, &application->num_canvas);
        }

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

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_init_application (
    ultk_application_t **application,
    const char *uidl_text,
    unsigned int uidl_text_len
)
{
    *application = malloc(sizeof(ultk_application_t));
    char *uidl_textbuf = malloc((uidl_text_len + 1) * sizeof(char));

    if (!*application || !uidl_textbuf)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    strncpy(uidl_textbuf, uidl_text, uidl_text_len);
    uidl_textbuf[uidl_text_len] = '\0';

    char *token = ultk_uidl_parser_skip(uidl_textbuf);

    if (!ultk_uidl_cond_adv_col(&token, "application"))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    } 




}
