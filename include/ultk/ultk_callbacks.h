#ifndef _ULTK_CALLBACKS_H
#define _ULTK_CALLBACKS_H

typedef enum   ultk_callback_return ultk_callback_return_t;
typedef struct ultk_callback_fn     ultk_callback_fn_t;

enum ultk_callback_return {
    ULTK_CALLBACK_SUCCESS,
    ULTK_CALLBACK_CONTINUE,
    ULTK_CALLBACK_ERROR
};

struct ultk_callback_fn {
    char *id;
    ultk_callback_return_t (*function)(void);
};

/* APPLICATION PROVIDED CALLBACKS */

ultk_callback_return_t
ultk_callback_init (
    void **application_data
);

ultk_callback_return_t
ultk_callback_frame (
    void *application_data
);

ultk_callback_return_t
ultk_callback_quit (
    void *application_data
);

#endif
