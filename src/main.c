#include <ultk/ultk_main.h>
#include <ultk/ultk_backend_api.h>
#include "main.h"
#include "application.h"

ultk_return_t
ultk_backend_callback_init (
    ultk_application_t **application,
    void **application_data,
    void *backend_state,
    int argc,
    char **argv
)
{
    ultk_return_t status;
    ultk_callback_return_t callback_status;

    char *uib_text;
    size_t uib_text_len;

    callback_status = ultk_callback_preinit(
        application_data,
        &uib_text, 
        &uib_text_len, 
        argc, 
        argv
    );

    switch (callback_status)
    {
        case ULTK_CALLBACK_SUCCESS:
        return ULTK_EXIT_CALLBACK_SUCCESS;
        break;

        case ULTK_CALLBACK_CONTINUE:
        break;

        case ULTK_CALLBACK_ERROR:
        return ULTK_ERROR_CALLBACK_ERROR;
        break;
    }

    if (uib_text == NULL || uib_text_len == 0)
    {
        return ULTK_ERROR_UIB_ERROR;
    }

    status = ultk_init_application_uib(uib_text, uib_text_len, application);

    if (status != ULTK_SUCCESS)
    {
        return status;
    }

    for (uint16_t i = 0; i < (*application)->num_canvas; i++)
    {
        ultk_color_rgba_t color_fill_bg = {
            .r = 127,
            .g = 127,
            .b = 127,
            .a = 255
        };

        status = ultk_backend_create_canvas(
            backend_state, 
            i, 
            (*application)->canvas[i].title,
            (*application)->canvas[i].size.x,
            (*application)->canvas[i].size.y,
            &(*application)->canvas[i].size.x,
            &(*application)->canvas[i].size.y,
            ULTK_COLOR_BACKGROUND,
            color_fill_bg
        );
    }

    callback_status = ultk_callback_postinit(*application_data, *application);

    switch (callback_status)
    {
        case ULTK_CALLBACK_SUCCESS:
        return ULTK_EXIT_CALLBACK_SUCCESS;
        break;

        case ULTK_CALLBACK_CONTINUE:
        break;

        case ULTK_CALLBACK_ERROR:
        return ULTK_ERROR_CALLBACK_ERROR;
        break;
    }

    return ULTK_CONTINUE;
}

ultk_return_t
ultk_backend_callback_frame (
    ultk_application_t *application,
    void *application_data,
    void *backend_state
)
{
    ultk_callback_return_t callback_status;

    callback_status = ultk_callback_frame(application_data, application);

    switch (callback_status)
    {
        case ULTK_CALLBACK_SUCCESS:
        return ULTK_EXIT_CALLBACK_SUCCESS;
        break;

        case ULTK_CALLBACK_CONTINUE:
        break;

        case ULTK_CALLBACK_ERROR:
        return ULTK_ERROR_CALLBACK_ERROR;
        break;
    }

    //draw ui

    return ULTK_CONTINUE;
}

ultk_return_t
ultk_backend_callback_event (
    ultk_application_t *application,
    void *application_data,
    void *backend_state
)
{
    //input handling
}

ultk_return_t
ultk_backend_callback_quit (
    ultk_application_t *application,
    void *application_data,
    void *backend_state
)
{
    ultk_callback_return_t callback_status;
    
    //destroy application struct

    callback_status = ultk_callback_quit(application_data);

    switch (callback_status)
    {
        case ULTK_CALLBACK_SUCCESS:
        case ULTK_CALLBACK_CONTINUE:
        break;

        case ULTK_CALLBACK_ERROR:
        return ULTK_ERROR_CALLBACK_ERROR;
        break;
    }

    return ULTK_EXIT_CALLBACK_SUCCESS;
}
