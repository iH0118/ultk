#ifndef _ULTK_WIDGET_H
#define _ULTK_WIDGET_H

typedef enum ultk_widget_type ultk_widget_type_t;
typedef struct ultk_widget    ultk_widget_t;

enum ultk_widget_type {
    ULTK_WIDGET_VOID,
    ULTK_WIDGET_ARRAY_STATIC,
    ULTK_WIDGET_ARRAY_DYNAMIC,
    ULTK_WIDGET_BUTTON,
    ULTK_WIDGET_CHECKBOX,
    ULTK_WIDGET_CONTAINER,
    ULTK_WIDGET_CONTAINER_Label,
    ULTK_WIDGET_CONTAINER_SPLIT,
    ULTK_WIDGET_CONTAINER_GRID,
    ULTK_WIDGET_PROGRESSBAR,
    ULTK_WIDGET_RADIOBUTTONS,
    ULTK_WIDGET_TEXT,
    ULTK_WIDGET_TEXT_INPUT,
    ULTK_WIDGET_TEXT_INPUT_NUMERIC,
};

struct ultk_widget {
    ultk_widget_type_t type;
    //add stuff here
};

#endif
