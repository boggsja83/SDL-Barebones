#pragma once

#include "SDL.h"
#include "Settings.h"

namespace ss
{
	class Input
	{
	private:
		SDL_Keycode		_Keys[KEYS_COUNT];
		bool			_KeyState[KEYS_COUNT];
		int				_KeyHeldCount[KEYS_COUNT];

	public:
		Input(): _Keys(),_KeyState(),_KeyHeldCount() {}
		Input(Input const& _i) { init_copy(_i); }
		~Input() {}

		int init();
		int init_copy(Input const &_i);
		int set_keys_state();
	};
}

