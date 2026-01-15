#ifndef _ULTK_UIDL_H_INTERNAL
#define _ULTK_UIDL_H_INTERNAL

#include <ultk/ultk.h>

/* UIDL_PARSER_UTIL */

char *
ultk_uidl_parser_skip (
    char *token
);

_Bool
ultk_uidl_conditional_advance (
    char **token,
    const char *target
);

_Bool
ultk_uidl_cond_adv_col (
    char **token,
    const char *target
);

/* UIDL_PARSER_SCALAR */

ultk_return_t
ultk_uidl_parse_bool (
    char **token,
    _Bool *target
);

ultk_return_t
ultk_uidl_parse_int (
    char **token,
    int *target
);

ultk_return_t
ultk_uidl_parse_string (
    char **token,
    char **target
);

/* UIDL_PARSER_ENUMS */

ultk_return_t
ultk_uidl_parse_canvas_type (
    char **token,
    ultk_canvas_type_t *type
);

ultk_return_t
ultk_uidl_parse_widget_type (
    char **token,
    ultk_widget_type_t *type
);

ultk_return_t
ultk_uidl_parse_array_alignment (
    char **token,
    ultk_array_alignment_t *alignment
);

/* UIDL_PARSER_WIDGET */

ultk_return_t
ultk_uidl_parse_field_array_static (
    char **token,
    ultk_widget_t *widget
);

ultk_return_t
ultk_uidl_parse_widget (
    char **token,
    ultk_widget_t **widget
);

ultk_return_t
ultk_uidl_parse_widget_array (
    char **token,
    ultk_widget_t **widget,
    int *num_widgets
);

#endif