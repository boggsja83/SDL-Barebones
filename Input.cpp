#include "Input.h"

int ss::Input::init(){

	return OK;
}

void ss::Input::init_copy(Input const& _i){
	for (int i = 0; i < SDL_NUM_SCANCODES; ++i) { this->_Keys[i] = _i._Keys[i]; }
}

int ss::Input::poll_events(){
	SDL_Event ev;

    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_KEYDOWN:
            _Keys[ev.key.keysym.scancode] = ev.key;
            break;

        case SDL_KEYUP:
            _Keys[ev.key.keysym.scancode] = ev.key;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (ev.button.button == SDL_BUTTON_LEFT) {
                std::cout << "mouse: x=" << ev.button.x << " y= " << ev.button.y << "\n";
            }
            break;

        case SDL_QUIT:
            return EXIT_LOOP;

            //case SDL_WINDOWEVENT:
            //	switch (ev.window.event) {
            //	case SDL_WINDOWEVENT_SIZE_CHANGED:
            //		return RESIZE_WINDOW;
            //	default:;
            //	}
            //default:;
            //}

        
        case SDL_MOUSEWHEEL:
            if (ev.wheel.y > 0) return MOUSEWHEEL_UP;
            else return MOUSEWHEEL_DOWN;

            break;
            
        /****************************************************************/
        case SDL_WINDOWEVENT:
            switch (ev.window.event) {
            case SDL_WINDOWEVENT_SHOWN:
                SDL_Log("Window %d shown", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_HIDDEN:
                SDL_Log("Window %d hidden", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_EXPOSED:
                SDL_Log("Window %d exposed", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_MOVED:
                SDL_Log("Window %d moved to %d,%d",
                    ev.window.windowID, ev.window.data1,
                    ev.window.data2);
                break;
            case SDL_WINDOWEVENT_RESIZED:
                SDL_Log("Window %d resized to %dx%d",
                    ev.window.windowID, ev.window.data1,
                    ev.window.data2);
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                SDL_Log("Window %d size changed to %dx%d",
                    ev.window.windowID, ev.window.data1,
                    ev.window.data2);
                    return RESIZE_WINDOW;
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                SDL_Log("Window %d minimized", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                SDL_Log("Window %d maximized", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_RESTORED:
                SDL_Log("Window %d restored", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_ENTER:
                SDL_Log("Mouse entered window %d",
                    ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_LEAVE:
                SDL_Log("Mouse left window %d", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
                SDL_Log("Window %d gained keyboard focus",
                    ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
                SDL_Log("Window %d lost keyboard focus",
                    ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_CLOSE:
                SDL_Log("Window %d closed", ev.window.windowID);
                break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
            case SDL_WINDOWEVENT_TAKE_FOCUS:
                SDL_Log("Window %d is offered a focus", ev.window.windowID);
                break;
            case SDL_WINDOWEVENT_HIT_TEST:
                SDL_Log("Window %d has a special hit test", ev.window.windowID);
                break;
#endif
            default:
                SDL_Log("Window %d got unknown event %d",
                    ev.window.windowID, ev.window.event);
                break;
            }
            /*****************************************************************************/
        }
    }

	return OK;
}

