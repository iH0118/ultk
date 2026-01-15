#include "alloc.h"
#include "ultk/ultk_common.h"
#include "ultk/ultk_widget.h"
#include <stdlib.h>


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
ultk_alloc_canvas_array (
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

ultk_return_t
ultk_alloc_widget (
    ultk_widget_t **widget
)
{
    *widget = malloc(sizeof(ultk_widget_t));

    if (!*widget)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    return ULTK_SUCCESS;
}

ultk_return_t
ultk_alloc_widget_array (
    ultk_widget_t **widget,
    unsigned int *num_widget
)
{
    *widget = realloc(*widget, ++(*num_widget) * sizeof(ultk_widget_t));

    if (!*widget)
    {
        return ULTK_ERROR_ALLOCATION_FAILED;
    }

    return ULTK_SUCCESS;
}
