#ifndef _ULTK_BACKEND_WAYLAND_H
#define _ULTK_BACKEND_WAYLAND_H

#include <ultk/ultk_backend_api.h>
#include <wayland-client.h>

typedef struct ultk_backend_wayland_appdata ultk_backend_wayland_appdata_t;

struct ultk_backend_wayland_appdata {
    ultk_application_t *application;

};

#endif