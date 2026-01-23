#include <stdlib.h>
#include <ultk/ultk.h>

ultk_callback_return_t
ultk_callback_preinit (
    void **application_data,
    char **uib_text,
    size_t *uib_text_len
)
{
    extern char *_binary_build_onebutton_uib_start;
    extern char *_binary_build_onebutton_uib_end;
    
    *application_data = NULL;
    *uib_text = _binary_build_onebutton_uib_start;
    *uib_text_len =
        _binary_build_onebutton_uib_end - _binary_build_onebutton_uib_start;

    return ULTK_CALLBACK_CONTINUE;
}

ultk_callback_return_t
ultk_callback_postinit (
    void *application_data,
    ultk_application_t *application
)
{
    return ULTK_CALLBACK_CONTINUE;
}

ultk_callback_return_t
ultk_callback_frame (
    void *application_data,
    ultk_application_t *application
)
{
    return ULTK_CALLBACK_CONTINUE;
}

ultk_callback_return_t
ultk_callback_quit (
    void *application_data
)
{
    return ULTK_CALLBACK_SUCCESS;
}
