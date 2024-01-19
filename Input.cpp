#include "Input.h"

int ss::Input::init()
{

	return OK;
}

int ss::Input::init_copy(Input const& _i)
{
	for (int i = 0; i < SDL_NUM_SCANCODES; ++i) { this->_Keys[i] = _i._Keys[i]; }

	return OK;
}

int ss::Input::poll_events()
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)){
		switch (ev.type){
		case SDL_KEYDOWN:
			_Keys[ev.key.keysym.scancode] = ev.key;
			break;
		
		case SDL_KEYUP:
			_Keys[ev.key.keysym.scancode] = ev.key;
			break;
		
		case SDL_QUIT:
			return EXIT_LOOP;
		
		case SDL_WINDOWEVENT:
			switch (ev.window.event) {
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				return RESIZE_WINDOW;
			default:;
			}
		default:;
		}
	}
	return OK;
}

