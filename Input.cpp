#include "Input.h"

int ss::Input::init()
{
	for (int i = 0; i < KEYS_COUNT; ++i) { _KeyState[i] = false; _KeyHeldCount[i] = 0; }
	
	_Keys[0] = SDLK_ESCAPE;
	_Keys[1] = SDLK_RETURN;
	_Keys[2] = SDLK_SPACE;
	_Keys[3] = SDLK_w;
	_Keys[4] = SDLK_a;
	_Keys[5] = SDLK_s;
	_Keys[6] = SDLK_d;

	return OK;
}

int ss::Input::init_copy(Input const& _i)
{
	for (int i = 0; i < KEYS_COUNT; ++i) 
	{ 
		this->_KeyState[i] = _i._KeyState[i]; 
		this->_Keys[i] = _i._Keys[i];
		this->_KeyHeldCount[i] = _i._KeyHeldCount[i];
	}

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
			for (int i=0; i< KEYS_COUNT;++i)
			{
				if (ev.key.keysym.sym == _Keys[i])
				{
					_KeyState[i] = true;
					_KeyHeldCount[i]++;
				}
			}
			break;
		case SDL_KEYUP:
			for (int i = 0; i < KEYS_COUNT; ++i)
			{
				if (ev.key.keysym.sym == _Keys[i])
				{
					_KeyState[i] = false;
					_KeyHeldCount[i] = 0;
				}
			}
			break;
		case SDL_QUIT:
			return QUIT_LOOP;
		default:;
		}
	}
	return OK;
}

