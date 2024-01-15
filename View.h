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
		SDL_Rect		_Interface[9];

		

	public:
		View():_WinWidth(0),_WinHeight(0),_WinMain(nullptr),_RenMain(nullptr),_Interface() {}
		View(View const& _v) { init_copy(_v); }
		~View()
		{
			SDL_DestroyRenderer(_RenMain);
			SDL_DestroyWindow(_WinMain);
		}

		inline SDL_Window*		win() { return _WinMain; }
		inline SDL_Renderer*	ren() { return _RenMain; }

		int		init();
		void	init_copy(View const& _v);
		void	init_interface_rects();
		int		draw_interface(SDL_Renderer*);

		//int set_color_bg(SDL_Renderer*,int,int,int,int);
		//int set_color_bg(SDL_Renderer*,SDL_Color);

	};
}
