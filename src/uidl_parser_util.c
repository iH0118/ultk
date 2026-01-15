#include "uidl.h"
#include <string.h>

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

_Bool
ultk_uidl_cond_adv_col (
    char **token,
    const char *target
)
{
    return ultk_uidl_conditional_advance(token, target) && ultk_uidl_conditional_advance(token, ":");
}
