#ifndef _ULTK_ALLOC_H_INTERNAL
#define _ULTK_ALLOC_H_INTERNAL

#include <ultk/ultk.h>

ultk_return_t
ultk_alloc_application_metadata (
    ultk_application_metadata_t **metadata
);

ultk_return_t
ultk_alloc_canvas_array (
    ultk_canvas_t **canvas,
    unsigned int *num_canvas
);

ultk_return_t
ultk_alloc_widget (
    ultk_widget_t **widget
);

#endif