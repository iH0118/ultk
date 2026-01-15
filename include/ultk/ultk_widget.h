#ifndef _ULTK_WIDGET_H
#define _ULTK_WIDGET_H

typedef enum   ultk_widget_type               ultk_widget_type_t;
typedef enum   ultk_array_alignment           ultk_array_alignment_t;
typedef enum   ultk_text_alignment_x          ultk_text_alignment_x_t;
typedef enum   ultk_text_alignment_y          ultk_text_alignment_y_t;
typedef enum   ultk_reflow_direction          ultk_reflow_direction_t;
//typedef struct ultk_widget_void               ultk_widget_void_t;
typedef struct ultk_widget_array_static       ultk_widget_array_static_t;
typedef struct ultk_widget_array_dynamic      ultk_widget_array_dynamic_t;
typedef struct ultk_widget_button             ultk_widget_button_t;
typedef struct ultk_widget_checkbox           ultk_widget_checkbox_t;
typedef struct ultk_widget_container          ultk_widget_container_t;
typedef struct ultk_widget_container_label    ultk_widget_container_label_t;
typedef struct ultk_widget_container_split    ultk_widget_container_split_t;
//typedef struct ultk_widget_container_grid     ultk_widget_container_grid_t;
typedef struct ultk_widget_progressbar        ultk_widget_progressbar_t;
typedef struct ultk_widget_radiobuttons       ultk_widget_radiobuttons_t;
typedef struct ultk_widget_text               ultk_widget_text_t;
typedef struct ultk_widget_text_input         ultk_widget_text_input_t;
typedef struct ultk_widget_text_input_numeric ultk_widget_text_input_numeric_t;
typedef struct ultk_widget                    ultk_widget_t;

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

//struct ultk_widget_void {};

struct ultk_widget_array_static {
    int num_rows;
    int num_cols;
    ultk_array_alignment_t alignment;
    _Bool scrollable_x;
    _Bool scrollable_y;
    ultk_widget_t **children;
};

struct ultk_widget_array_dynamic {
    int num_children;
    ultk_array_alignment_t alignment;
    _Bool keep_grid;
    ultk_reflow_direction_t reflow_direction;
    int max_reflow_sections;
    ultk_widget_t **children;
};

struct ultk_widget_button {
    char *label;
    ultk_text_alignment_x_t label_align_x;
    ultk_text_alignment_y_t label_align_y;
    struct {
        int x;
        int y;
    } size_min;
    struct {
        int x;
        int y;
    } size_max;
    char *callback_id_press;
};

struct ultk_widget_checkbox {
    char *label;
    _Bool checked;
    char *callback_id_check;
    char *callback_id_uncheck;
};

struct ultk_widget_container {
    struct {
        float l;
        float r;
        float t;
        float b;
    } padding_relative;
    struct {
        int l;
        int r;
        int t;
        int b;
    } padding_absolute;
    ultk_widget_t *child;
};

struct ultk_widget_container_label {
    char *label;
    ultk_text_alignment_x_t label_align;
    _Bool border;
    ultk_widget_t *child;
};

struct ultk_widget {
    ultk_widget_type_t type;
    char *id;
    union {
        ultk_widget_array_static_t array_static;
        ultk_widget_array_dynamic_t array_dynamic;
        ultk_widget_button_t button;
        ultk_widget_checkbox_t checkbox;
        ultk_widget_container_t container;
        ultk_widget_container_label_t container_label;
    };
};

#endif
