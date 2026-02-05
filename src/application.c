#include <stdlib.h>
#include <string.h>
#include "uib_scalars.h"
#include "canvas.h"
#include "application.h"

ultk_return_t
ultk_init_application_uib (
    const char *uib_text,
    unsigned int uib_text_len,
    ultk_application_t **application
)
{
    *application = malloc(sizeof(ultk_application_t));

    if (*application == NULL)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    (*application)->metadata = malloc(sizeof(ultk_application_metadata_t));

    if ((*application)->metadata == NULL)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    if (uib_text_len < 7 || strncmp(uib_text, "UIB", 3))
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    unsigned int position = 3;

    uint32_t application_size;

    ultk_uib_parse_uint32(
        uib_text,
        uib_text_len,
        &position,
        &application_size
    );

    if (uib_text_len != application_size + 3)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        &position,
        &(*application)->metadata->name
    );

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        &position,
        &(*application)->metadata->version
    );

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        &position,
        &(*application)->metadata->id
    );

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        &position,
        &(*application)->metadata->creator
    );

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        &position,
        &(*application)->metadata->creator
    );

    ultk_uib_parse_string_after_len(
        uib_text,
        uib_text_len,
        &position,
        &(*application)->metadata->url
    );

    ultk_uib_parse_uint16(
        uib_text,
        uib_text_len,
        &position,
        &(*application)->num_canvas
    );

    (*application)->canvas =
        malloc((*application)->num_canvas * sizeof(ultk_canvas_t));

    ultk_return_t status;

    uint16_t i;
    for (i = 0; i < (*application)->num_canvas; i++)
    {
        status = ultk_create_canvas_uib(
            uib_text,
            uib_text_len,
            &position,
            &(*application)->canvas[i]
        );

        if (status != ULTK_SUCCESS)
        {
            return status;
        }
    }

    if (position != uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    return ULTK_SUCCESS;
}