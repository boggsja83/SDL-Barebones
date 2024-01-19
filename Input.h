#pragma once

#include "SDL.h"
#include "Settings.h"

namespace ss
{
	class Input
	{
	private:

	public:
		Input() : _Keys() {}
		Input(Input const& _i) { init_copy(_i); }
		~Input() {}

		int init();
		int init_copy(Input const &_i);
		int poll_events();

		SDL_KeyboardEvent	_Keys[SDL_NUM_SCANCODES];
		
	};
}

