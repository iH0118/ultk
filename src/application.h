#ifndef _ULTK_APPLICATION_H_INTERNAL
#define _ULTK_APPLICATION_H_INTERNAL

#include <ultk/ultk_application.h>

ultk_return_t
ultk_build_application (
    ultk_application_t **application,
    const char *uidl_text,
    unsigned int uidl_text_len
);

#endif