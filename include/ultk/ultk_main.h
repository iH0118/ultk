#ifndef _ULTK_MAIN_H
#define _ULTK_MAIN_H

#include <ultk/ultk_application.h>
#include <stdlib.h>

/* APPLICATION PROVIDED CALLBACKS */

ultk_callback_return_t
ultk_callback_preinit (
    void **application_data,
    char **uib_text,
    size_t *uib_text_len,
    int argc,
    char **argv
);

ultk_callback_return_t
ultk_callback_postinit (
    void *application_data,
    ultk_application_t *application
);

ultk_callback_return_t
ultk_callback_frame (
    void *application_data,
    ultk_application_t *application
);

ultk_callback_return_t
ultk_callback_quit (
    void *application_data
);

#endif
