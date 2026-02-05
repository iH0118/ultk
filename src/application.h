#ifndef _ULTK_APPLICATION_H_INTERNAL
#define _ULTK_APPLICATION_H_INTERNAL

#include <ultk/ultk_common.h>
#include <ultk/ultk_application.h>

ultk_return_t
ultk_init_application_uib (
    const char *uib_text,
    unsigned int uib_text_len,
    ultk_application_t **application
);

#endif