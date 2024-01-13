#pragma once

#include "SDL.h"
#include "Settings.h"

namespace ss
{
	class Input
	{
	private:
		

	public:
		Input() : _Keys() {}//, _KeyState(), _KeyHeldCount() {}
		Input(Input const& _i) { init_copy(_i); }
		~Input() {}

		int init();
		int init_copy(Input const &_i);
		int set_keys_state();

		SDL_KeyboardEvent	_Keys[SDL_NUM_SCANCODES];
		//bool			_KeyState[SDL_NUM_SCANCODES];
		//int				_KeyHeldCount[SDL_NUM_SCANCODES];
		
	};
}

