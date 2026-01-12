#include <ultk/ultk.h>

ultk_callback_return_t
ultk_callback_init (
    void **application_data,
    char **uidl_text,
    unsigned int *uidl_text_len
)
{

}

ultk_callback_return_t
ultk_callback_frame (
    void *application_data
)
{
    return ULTK_CALLBACK_CONTINUE;
}

ultk_callback_return_t
ultk_callback_quit (
    void *application_data
)
{

}
