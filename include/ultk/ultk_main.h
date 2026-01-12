#ifndef _ULTK_MAIN_H
#define _ULTK_MAIN_H

#include <ultk/ultk_application.h>

/* APPLICATION PROVIDED CALLBACKS */

ultk_callback_return_t
ultk_callback_preinit (
    void **application_data,
    char **uidl_text,
    unsigned int *uidl_text_len
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
