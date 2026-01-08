#ifndef _ULTK_APPLICATION_H
#define _ULTK_APPLICATION_H

#include <ultk/ultk_canvas.h>

typedef struct ultk_application          ultk_application_t;
typedef struct ultk_application_metadata ultk_application_metadata_t;

struct ultk_application_metadata {
    char *name;
    char *version;
    char *id;
    char *creator;
    char *copyright;
    char *url;
};

struct ultk_application {
    ultk_application_metadata_t metadata;
    unsigned int canvas_count;
    ultk_canvas_t *canvas;
};

#endif