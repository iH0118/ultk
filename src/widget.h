#ifndef _ULTK_WIDGET_H_INTERNAL
#define _ULTK_WIDGET_H_INTERNAL

#include <ultk/ultk_common.h>
#include <ultk/ultk_widget.h>

ultk_return_t
ultk_create_widget_uib (
    const char *uib_text,
    unsigned int uib_text_len,
    unsigned int *position,
    ultk_widget_t *widget
);

ultk_return_t
ultk_draw_widget (
    ultk_widget_t *widget
);

ultk_return_t
ultk_destroy_widget (
    ultk_widget_t *widget
);

#endif