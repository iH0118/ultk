#include "application.h"
#include "ultk/ultk_application.h"
#include "ultk/ultk_canvas.h"
#include "ultk/ultk_common.h"
#include <stdlib.h>
#include <string.h>

typedef enum ultk_uidl_object_type ultk_uidl_object_type_t;
typedef struct ultk_uidl_object ultk_uidl_object_t;

enum ultk_uidl_object_type {
    ULTK_UIDL_OBJECT_NONE,
    ULTK_UIDL_OBJECT_BOOL,
    ULTK_UIDL_OBJECT_INT,
    ULTK_UIDL_OBJECT_FLOAT,
    ULTK_UIDL_OBJECT_STRING,
    ULTK_UIDL_OBJECT_LIST,
    ULTK_UIDL_OBJECT_ARRAY,
    ULTK_UIDL_OBJECT_APPLICATION,
    ULTK_UIDL_OBJECT_METADATA,
    ULTK_UIDL_OBJECT_CANVAS,
    ULTK_UIDL_OBJECT_CANVAS_LIST,
    ULTK_UIDL_OBJECT_WIDGET,
    ULTK_UIDL_OBJECT_WIDGET_ARRAY,
    ULTK_UIDL_OBJECT_ID,
    ULTK_UIDL_OBJECT_ENUM_CANVAS_TYPE,
    ULTK_UIDL_OBJECT_ENUM,
    ULTK_UIDL_OBJECT_ENUM_WIDGET_TYPE,
    ULTK_UIDL_OBJECT_ENUM_WIDGET_ALIGNMENT,
    ULTK_UIDL_OBJECT_ENUM_REFLOW_DIRECTION,
    ULTK_UIDL_OBJECT_ENUM_LABEL_ALIGN_X,
    ULTK_UIDL_OBJECT_ENUM_LABEL_ALIGN_Y,
    ULTK_UIDL_OBJECT_ERROR = -1
};

ultk_return_t
ultk_alloc_application_metadata (
    ultk_application_metadata_t **metadata
)
{
    *metadata = calloc(1, sizeof(ultk_application_metadata_t));

    if (!*metadata)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_alloc_canvas (
    ultk_canvas_t **canvas,
    unsigned int *num_canvas
)
{
    *canvas = realloc(*canvas, ++(*num_canvas) * sizeof(ultk_canvas_t));

    if (!*canvas)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    return ULTK_SUCCESS;
}


char *
ultk_uidl_parser_skip (
    char *token
)
{
    int wslen = strspn(token, " \f\n\r\t\v");

    if (token[wslen] == '#')
    {
        return ultk_uidl_parser_skip(strchr(token + wslen, '\n') + 1);
    }

    return token + wslen;
}

_Bool
ultk_uidl_conditional_advance (
    char **token,
    const char *target
)
{
    int target_len = strlen(target);

    if (!strncmp(*token, target, target_len))
    {
        *token = ultk_uidl_parser_skip(*token + target_len);
        return 1;
    }

    return 0;
}

ultk_return_t
ultk_uidl_parse_string (
    char **token,
    char **string
)
{
    if (!ultk_uidl_conditional_advance(token, "\""))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    int len = strcspn(*token, "\"");

    *string = malloc(len + 1);
    if (!*string)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    strncpy(*string, *token, len);

    *token += len;

    if (!ultk_uidl_conditional_advance(token, "\""))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uidl_parse_metadata (
    char **token,
    ultk_application_metadata_t **metadata
)
{
    if (!ultk_uidl_conditional_advance(token, "{"))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    ultk_return_t status = ultk_alloc_application_metadata(metadata);

    if (status != ULTK_SUCCESS)
    {
        return status;
    }

    while (1)
    {
        if (ultk_uidl_conditional_advance(token, "name") &&
            ultk_uidl_conditional_advance(token, ":"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->name);
        }

        if (ultk_uidl_conditional_advance(token, "version") &&
            ultk_uidl_conditional_advance(token, ":"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->version);
        }

        if (ultk_uidl_conditional_advance(token, "id") &&
            ultk_uidl_conditional_advance(token, ":"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->id);
        }

        if (ultk_uidl_conditional_advance(token, "creator") &&
            ultk_uidl_conditional_advance(token, ":"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->creator);
        }

        if (ultk_uidl_conditional_advance(token, "copyright") &&
            ultk_uidl_conditional_advance(token, ":"))
        {
            status = ultk_uidl_parse_string(token, &(*metadata)->copyright);
        }

        if (ultk_uidl_conditional_advance(token, "url") &&
            ultk_uidl_conditional_advance(token, ":"))
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

        while (1)
        {
            //parse canvas struct
        }

        if (ultk_uidl_conditional_advance(token, ","))
        {
            continue;
        }

        if (ultk_uidl_conditional_advance(token, "]"))
        {
            break;
        }
    }

    return ULTK_SUCCESS;
}




ultk_return_t
ultk_uidl_parse_application (
    char **token,
    ultk_application_t *application
)
{
    if (!ultk_uidl_conditional_advance(token, "{"))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    while (1)
    {
        if (ultk_uidl_conditional_advance(token, "metadata") &&
            ultk_uidl_conditional_advance(token, ":"))
        {
            if (ultk_uidl_parse_metadata(token, &application->metadata))
            {
                return ULTK_ERROR_UIDL_SYNTAX;
            }
        }

        if (ultk_uidl_conditional_advance(token, "canvas") &&
            ultk_uidl_conditional_advance(token, ":"))
        {
            //add stuff here
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

    if (!ultk_uidl_conditional_advance(&token, "application") ||
        !ultk_uidl_conditional_advance(&token, ":"))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    } 
    



}
