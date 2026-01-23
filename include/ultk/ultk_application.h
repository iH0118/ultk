#ifndef _ULTK_APPLICATION_H
#define _ULTK_APPLICATION_H

#include <stdint.h>
#include <ultk/ultk_canvas.h>

typedef enum   ultk_callback_return      ultk_callback_return_t;
typedef struct ultk_callback_fn          ultk_callback_fn_t;
typedef struct ultk_application          ultk_application_t;
typedef struct ultk_application_metadata ultk_application_metadata_t;

enum ultk_callback_return {
    ULTK_CALLBACK_SUCCESS,
    ULTK_CALLBACK_CONTINUE,
    ULTK_CALLBACK_ERROR
};

struct ultk_callback_fn {
    char *id;
    ultk_callback_return_t (*function)(void*);
    void *passed_pointer;
};

struct ultk_application_metadata {
    char *name;
    char *version;
    char *id;
    char *creator;
    char *copyright;
    char *url;
};

struct ultk_application {
    ultk_application_metadata_t *metadata;
    uint16_t num_canvas;
    ultk_canvas_t *canvas;
    uint16_t num_callbacks;
    ultk_callback_fn_t *callbacks;
};

ultk_return_t
ultk_register_callback (
    ultk_application_t *application,
    char *id,
    ultk_callback_return_t (*function)(void*),
    void *passed_args
);

ultk_return_t
ultk_unregister_callback (
    ultk_application_t *application,
    char* id
);

#endif