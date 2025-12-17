#include "backend.h"

ultk_canvas_id_t
ultk_backend_sdl3_get_canvas_id (
    SDL_WindowID window_id
)
{
    int canvas_id;
    for (canvas_id = 0; canvas_id < _ULTK_BACKEND_MAX_CANVAS_COUNT; canvas_id++)
    {
        if (SDL_GetWindowID(canvas_index[canvas_id].window) == window_id)
        {
            return canvas_id;
        }
    }

    return -1;
}

ultk_return_t
ultk_backend_query_input (
    ultk_input_queue_t *input_queue
)
{
    if (!input_queue)
    {
        return ULTK_BACKEND_ERROR_INPUT_QUEUE_NOT_INITIALIZED;
    }

    SDL_Event event_be;
    ultk_input_event_t *event;

    while (SDL_PollEvent(&event_be))
    {
        if (input_queue->num_events >= _ULTK_BACKEND_MAX_EVENT_COUNT)
        {
            return ULTK_BACKEND_INPUT_QUEUE_FULL;
        }

        event = &(input_queue->events[input_queue->num_events++]);

        switch (event_be.common.type)
        {
            case SDL_EVENT_QUIT:
            event->event_type =  ULTK_INPUT_EVENT_APPLICATION_QUIT;
            break;

            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            event->event_type = ULTK_INPUT_EVENT_CANVAS_QUIT;
            event->canvas_quit.canvas_id =
                ultk_backend_sdl3_get_canvas_id(event_be.window.windowID);
            break;

            case SDL_EVENT_WINDOW_RESIZED:
            event->event_type = ULTK_INPUT_EVENT_CANVAS_RESIZE;
            event->canvas_resize.canvas_id =
                ultk_backend_sdl3_get_canvas_id(event_be.window.windowID);
            event->canvas_resize.size_x = event_be.window.data1;
            event->canvas_resize.size_y = event_be.window.data2;
            break;

            case SDL_EVENT_KEY_DOWN:
            case SDL_EVENT_KEY_UP:
            event->event_type = ULTK_INPUT_EVENT_KEYBOARD;
            event->keyboard.canvas_id =
                ultk_backend_sdl3_get_canvas_id(event_be.window.windowID);
            event->keyboard.pressed = event_be.key.down;
            event->keyboard.repeat = event_be.key.repeat;
            event->keyboard.key = event_be.key.key; //this is just preliminary
            break;

            case SDL_EVENT_MOUSE_MOTION:
            event->event_type = ULTK_INPUT_EVENT_MOUSE_MOTION;
            event->mouse_motion.canvas_id =
                ultk_backend_sdl3_get_canvas_id(event_be.window.windowID);
            event->mouse_motion.start_x = event_be.motion.x;
            event->mouse_motion.start_y = event_be.motion.y;
            event->mouse_motion.dist_x = event_be.motion.xrel;
            event->mouse_motion.dist_y = event_be.motion.yrel;
            break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
            case SDL_EVENT_MOUSE_BUTTON_UP:
            event->event_type = ULTK_INPUT_EVENT_MOUSE_BUTTON;
            event->mouse_button.canvas_id =
                ultk_backend_sdl3_get_canvas_id(event_be.window.windowID);
            event->mouse_button.button = event_be.button.button;
            event->mouse_button.pressed = event_be.button.down;
            event->mouse_button.num_clicks = event_be.button.clicks;
            event->mouse_button.pos_x = event_be.button.x;
            event->mouse_button.pos_y = event_be.button.y;
            break;

            case SDL_EVENT_MOUSE_WHEEL:
            event->event_type = ULTK_INPUT_EVENT_MOUSE_SCROLL;
            event->mouse_scroll.canvas_id =
                ultk_backend_sdl3_get_canvas_id(event_be.window.windowID);
            event->mouse_scroll.pos_x = event_be.wheel.mouse_x;
            event->mouse_scroll.pos_y = event_be.wheel.mouse_y;
            event->mouse_scroll.dist_x = event_be.wheel.x;
            event->mouse_scroll.dist_y = event_be.wheel.y;
            break;

            default:
            input_queue->num_events--;
            break;
        }
    }

    return ULTK_SUCCESS;
}