#include "uidl.h"
#include <stdlib.h>
#include <string.h>

ultk_return_t
ultk_uidl_parse_bool (
    char **token,
    _Bool *target
)
{
    if (ultk_uidl_conditional_advance(token, "true"))
    {
        *target = 1;
        return ULTK_SUCCESS;
    }

    if (ultk_uidl_conditional_advance(token, "false"))
    {
        *target = 0;
        return ULTK_SUCCESS;
    }

    return ULTK_ERROR_UIDL_SYNTAX;
}

ultk_return_t
ultk_uidl_parse_int (
    char **token,
    int *target
)
{
    int len = strcspn(*token, " \f\n\r\t\v");
    char *buf = malloc(len + 1);

    if (!buf)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    strncpy(buf, *token, len);
    buf[len] = '\0';

    *target = atoi(buf);

    free(buf);

    *token += len;

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_uidl_parse_string (
    char **token,
    char **target
)
{
    if (!ultk_uidl_conditional_advance(token, "\""))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    int len = strcspn(*token, "\"");

    *target = malloc(len + 1);
    if (!*target)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    strncpy(*target, *token, len);

    *token += len;

    if (!ultk_uidl_conditional_advance(token, "\""))
    {
        return ULTK_ERROR_UIDL_SYNTAX;
    }

    return ULTK_SUCCESS;
}
