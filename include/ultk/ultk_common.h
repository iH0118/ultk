#ifndef _ULTK_COMMON_H
#define _ULTK_COMMON_H

#include <stdint.h>

typedef int              ultk_screen_coord_t;
typedef enum ultk_return ultk_return_t;

enum ultk_return {
    ULTK_SUCCESS                                   =  0x00,
    ULTK_BACKEND_INPUT_QUEUE_FULL                  =  0x1001,
    ULTK_ERROR_UNSPECIFIED                         = -0x01,
    ULTK_BACKEND_ERROR_UNSPECIFIED                 = -0x1001,
    ULTK_BACKEND_ERROR_INIT_ERROR                  = -0x1002,
    ULTK_BACKEND_ERROR_NOT_INITIALIZED             = -0x1003,
    ULTK_BACKEND_ERROR_MAX_CANVAS_COUNT_REACHED    = -0x1004,
    ULTK_BACKEND_ERROR_CANVAS_INDEX_OUT_OF_RANGE   = -0x1005,
    ULTK_BACKEND_ERROR_CANVAS_CREATION_ERROR       = -0x1006,
    ULTK_BACKEND_ERROR_CANVAS_DOESNT_EXIST         = -0x1007,
    ULTK_BACKEND_ERROR_INPUT_QUEUE_NOT_INITIALIZED = -0x1008,
    ULTK_BACKEND_ERROR_RENDER_ERROR                = -0x1009
};

#endif
