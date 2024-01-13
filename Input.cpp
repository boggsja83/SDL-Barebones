#include "Input.h"

int ss::Input::init()
{
	//for (int i = 0; i < KEYS_COUNT; ++i) { _KeyState[i] = false; _KeyHeldCount[i] = 0; }
	//
	//_Keys[0] = SDL_SCANCODE_ESCAPE;
	//_Keys[1] = SDL_SCANCODE_RETURN;
	//_Keys[2] = SDL_SCANCODE_SPACE;
	//_Keys[3] = SDL_SCANCODE_W;
	//_Keys[4] = SDL_SCANCODE_A;
	//_Keys[5] = SDL_SCANCODE_S;
	//_Keys[6] = SDL_SCANCODE_D;

	return OK;
}

int ss::Input::init_copy(Input const& _i)
{
	//for (int i = 0; i < KEYS_COUNT; ++i) 
	//{ 
	//	this->_Keys[i] = _i._Keys[i];
	//	this->_KeyState[i] = _i._KeyState[i]; 
	//	this->_KeyHeldCount[i] = _i._KeyHeldCount[i];
	//}
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
			//for (int i=0; i< KEYS_COUNT;++i)
			//{
			//	if (ev.key.keysym.sym == _Keys[i])
			//	{
			//		_KeyState[i] = true;
			//		_KeyHeldCount[i]++;
			//	}
			//}
			_Keys[ev.key.keysym.scancode] = ev.key;

			break;
		case SDL_KEYUP:
			//for (int i = 0; i < KEYS_COUNT; ++i)
			//{
			//	if (ev.key.keysym.sym == _Keys[i])
			//	{
			//		_KeyState[i] = false;
			//		_KeyHeldCount[i] = 0;
			//	}
			//}
			_Keys[ev.key.keysym.scancode] = ev.key;

			break;
		case SDL_QUIT:
			return EXIT_LOOP;
		default:;
		}
	}
	return OK;
}

