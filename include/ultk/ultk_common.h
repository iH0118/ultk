#ifndef _ULTK_COMMON_H
#define _ULTK_COMMON_H

#include <stdint.h>

typedef uint16_t         ultk_screen_coord_t;
typedef enum ultk_return ultk_return_t;

enum ultk_return {
    ULTK_SUCCESS                             =  0x00,
    ULTK_ERROR_UNSPECIFIED                   = -0x01,
    ULTK_ERROR_ALLOCATION_FAILED             = -0x02,
    ULTK_ERROR_UIB_ERROR                     = -0x03,
    ULTK_BACKEND_ERROR_UNSPECIFIED           = -0x1001,
    ULTK_BACKEND_ERROR_ALLOCATION_FAILED     = -0x1002,
    ULTK_BACKEND_ERROR_CANVAS_ALREADY_EXISTS = -0x1003,
    ULTK_BACKEND_ERROR_CANVAS_DOESNT_EXIST   = -0x1004,
    ULTK_BACKEND_ERROR_COULDNT_CREATE_CANVAS = -0x1005,
    ULTK_BACKEND_ERROR_RENDER_ERROR          = -0x1006
};

#endif
