#pragma once

#include "SDL.h"

#include "Settings.h"
#include "RandNum.h"

namespace ss
{
	class View
	{
	private:
		int				_WinWidth,
						_WinHeight;

		SDL_Window*		_WinMain;
		SDL_Renderer*	_RenMain;
		SDL_Rect		_Interface[9];

		int		BORDER_INTERFACE_1;
		int		BORDER_INTERFACE_2;
		int		BORDER_INTERFACE_3;
		int		BORDER_INTERFACE_4;
		int		BORDER_INTERFACE_5;
		int		BORDER_INTERFACE_6;

		void	set_borders();
		void	set_interface_rects();

	public:
		View():_WinWidth(0),_WinHeight(0),_WinMain(nullptr),_RenMain(nullptr),_Interface() {
			BORDER_INTERFACE_1 = 0;
			BORDER_INTERFACE_2 = 0;
			BORDER_INTERFACE_3 = 0;
			BORDER_INTERFACE_4 = 0;
			BORDER_INTERFACE_5 = 0;
			BORDER_INTERFACE_6 = 0;
		}

		View(View const& _v) { init_copy(_v); }
		~View()
		{
			SDL_DestroyRenderer(_RenMain);
			SDL_DestroyWindow(_WinMain);
		}

		inline SDL_Window*		win() { return _WinMain; }
		inline SDL_Renderer*	ren() { return _RenMain; }

		inline void	set_win_width	(int _w) { _WinWidth = _w; }
		inline void	set_win_height	(int _h) { _WinHeight = _h; }

		int		init();
		void	init_copy(View const& _v);
		int		draw_interface(SDL_Renderer*);
		int		draw_grid(SDL_Renderer*,int,int) const;
		


	};
}
