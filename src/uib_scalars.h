#ifndef _ULTK_UIB_SCALARS_H_INTERNAL
#define _ULTK_UIB_SCALARS_H_INTERNAL

#include <ultk/ultk_common.h>

ultk_return_t
ultk_uib_parse_bool (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    _Bool *target
);

ultk_return_t
ultk_uib_parse_uint8 (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    uint8_t *target
);

ultk_return_t
ultk_uib_parse_uint16 (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    uint16_t *target
);

ultk_return_t
ultk_uib_parse_uint32 (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    uint32_t *target
);

ultk_return_t
ultk_uib_parse_float (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    float *target
);

ultk_return_t
ultk_uib_parse_string (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    unsigned int target_len,
    char **target
);

ultk_return_t
ultk_uib_parse_string_after_len (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    char **target
);

#endif
