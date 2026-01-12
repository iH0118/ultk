#ifndef _ULTK_UIDL_H
#define _ULTK_UIDL_H

#include "ultk/ultk_common.h"

ultk_return_t
ultk_build_application_from_uidl (
    const char *uidl_text,
    unsigned int uidl_text_len
);

#endif