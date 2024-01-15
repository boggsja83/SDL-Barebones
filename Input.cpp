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

int ss::Input::set_keys_state()
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_KEYDOWN:
			_Keys[ev.key.keysym.scancode] = ev.key;
			break;
		case SDL_KEYUP:
			_Keys[ev.key.keysym.scancode] = ev.key;
			break;
		case SDL_QUIT:
			return EXIT_LOOP;
		default:;
		}
	}
	return OK;
}

