#pragma once

#include "SDL.h"
#include "Settings.h"

namespace ss
{
	class View
	{
	private:
		int		_WinWidth,
				_WinHeight;

		SDL_Window*		_WinMain;
		SDL_Renderer*	_RenMain;

		

	public:
		View():_WinWidth(0),_WinHeight(0),_WinMain(nullptr),_RenMain(nullptr) {}
		View(View const &_v)
		{
			this->_WinWidth = _v._WinWidth;
			this->_WinHeight = _v._WinHeight;
			this->_WinMain = _v._WinMain;
			this->_RenMain = _v._RenMain;
		}
		~View()
		{
			SDL_DestroyRenderer(_RenMain);
			SDL_DestroyWindow(_WinMain);
		}

		int init();
		inline SDL_Window* win() { return _WinMain; }
		inline SDL_Renderer* ren() { return _RenMain; }

	};
}
