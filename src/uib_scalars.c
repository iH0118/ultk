#include <stdlib.h>
#include <string.h>
#include "uib_scalars.h"

ultk_return_t
ultk_uib_parse_bool (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    _Bool *target
)
{
    if (*position + 1 >= uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    *target = uib_text[(*position)++];

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uib_parse_uint8 (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    uint8_t *target
)
{
    if (*position + 1 >= uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    *target = uib_text[(*position)++];

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uib_parse_uint16 (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    uint16_t *target
)
{
    if (*position + 2 >= uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    *target = uib_text[(*position)++] + (uib_text[(*position)++] << 8);

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uib_parse_uint32 (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    uint32_t *target
)
{
    if (*position + 4 >= uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    *target = uib_text[(*position)++] + (uib_text[(*position)++] << 8) +
        (uib_text[(*position)++] << 16) + (uib_text[(*position)++] << 24);

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uib_parse_float (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    float *target
)
{
    if (*position + 4 >= uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    union {
        float val_float;
        uint32_t val_uint;
    } target_bytes;

    target_bytes.val_uint =
        uib_text[(*position)++] + (uib_text[(*position)++] << 8) +
        (uib_text[(*position)++] << 16) + (uib_text[(*position)++] << 24);;

    *target = target_bytes.val_float;

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uib_parse_string (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    unsigned int target_len,
    char **target
)
{
    if (*position + target_len >= uib_text_len)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    *target = malloc(target_len + 1);
    strncpy(*target, uib_text + *position, target_len);
    *target[target_len] = '\0';
    *position += target_len;

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uib_parse_string_after_len (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    char **target
)
{
    uint16_t target_len;

    if (ultk_uib_parse_uint16(
            uib_text,
            uib_text_len,
            position,
            &target_len
        ) != ULTK_SUCCESS ||
        ultk_uib_parse_string(
            uib_text,
            uib_text_len,
            position,
            target_len, target
        ) != ULTK_SUCCESS)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    return ULTK_SUCCESS;
}
