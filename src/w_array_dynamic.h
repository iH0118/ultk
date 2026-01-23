#ifndef _ULTK_W_ARRAY_DYNAMIC_H_INTERNAL
#define _ULTK_W_ARRAY_DYNAMIC_H_INTERNAL

#include <ultk/ultk_common.h>
#include <ultk/ultk_widget.h>

ultk_return_t
ultk_uib_parse_w_array_dynamic (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    ultk_widget_t *widget
);

#endif