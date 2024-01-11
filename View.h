#pragma once

#include "SDL.h"
#include "Settings.h"

namespace ss
{
	class View
	{
	private:
		int		winWidth,
				winHeight;

		SDL_Window*		winMain;
		SDL_Renderer*	renMain;

	public:
		View():winWidth(0),winHeight(0),winMain(nullptr),renMain(nullptr) {}
		View(View const &_v)
		{
			this->winWidth = _v.winWidth;
			this->winHeight = _v.winHeight;
			this->winMain = _v.winMain;
			this->renMain = _v.renMain;
		}
		~View()
		{
			SDL_DestroyRenderer(renMain);
			SDL_DestroyWindow(winMain);
			SDL_Quit();
		}

		int init();
	};
}
