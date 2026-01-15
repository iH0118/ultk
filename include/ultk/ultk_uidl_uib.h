#ifndef _ULTK_UIDL_UIB_H
#define _ULTK_UIDL_UIB_H

typedef enum ultk_widget_type      ultk_widget_type_t;
typedef enum ultk_array_alignment  ultk_array_alignment_t;
typedef enum ultk_text_alignment_x ultk_text_alignment_x_t;
typedef enum ultk_text_alignment_y ultk_text_alignment_y_t;
typedef enum ultk_reflow_direction ultk_reflow_direction_t;

enum ultk_widget_type {
    ULTK_WIDGET_NULL,
    ULTK_WIDGET_VOID,
    ULTK_WIDGET_ARRAY_STATIC,
    ULTK_WIDGET_ARRAY_DYNAMIC,
    ULTK_WIDGET_BUTTON,
    ULTK_WIDGET_CHECKBOX,
    ULTK_WIDGET_CONTAINER,
    ULTK_WIDGET_CONTAINER_LABEL,
    ULTK_WIDGET_CONTAINER_SPLIT,
    //ULTK_WIDGET_CONTAINER_GRID,
    ULTK_WIDGET_PROGRESSBAR,
    ULTK_WIDGET_RADIOBUTTONS,
    ULTK_WIDGET_TEXT,
    ULTK_WIDGET_TEXT_INPUT,
    ULTK_WIDGET_TEXT_INPUT_NUMERIC,
};

enum ultk_array_alignment {
    ULTK_ARRAY_ALIGN_LEFT,
    ULTK_ARRAY_ALIGN_CENTER,
    ULTK_ARRAY_ALIGN_RIGHT,
    ULTK_ARRAY_ALIGN_FILL
};

enum ultk_text_alignment_x {
    ULTK_TEXT_ALIGN_LEFT,
    ULTK_TEXT_ALIGN_HCENTER,
    ULTK_TEXT_ALIGN_RIGHT
};

enum ultk_text_alignment_y {
    ULTK_TEXT_ALIGN_TOP,
    ULTK_TEXT_ALIGN_VCENTER,
    ULTK_TEXT_ALIGN_BOTTOM
};

enum ultk_reflow_direction {
    ULTK_REFLOW_HORIZONTAL,
    ULTK_REFLOW_VERTICAL
};


#endif