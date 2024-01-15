#include "View.h"

int ss::View::init(){
	SDL_Init(SDL_INIT_VIDEO);
	//SDL_Init(SDL_INIT_EVERYTHING);

	_WinWidth = WIN_WIDTH;
	_WinHeight = WIN_HEIGHT;

	_WinMain = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	if (!_WinMain) { return FAIL_CREATE_WIN; }

	_RenMain = SDL_CreateRenderer(_WinMain, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!_RenMain) { return FAIL_CREATE_REND; }

	init_interface_rects();

	return OK;
}

void ss::View::init_copy(View const& _v) {
	for (int i = 0; i < 9; ++i) this->_Interface[i] = _v._Interface[i];

	this->_WinWidth =	_v._WinWidth;
	this->_WinHeight =	_v._WinHeight;
	this->_WinMain =	_v._WinMain;
	this->_RenMain =	_v._RenMain;
}

void ss::View::init_interface_rects() {
	_Interface[0].x = 0;
	_Interface[0].y = 0;
	_Interface[0].w = WIN_WIDTH;
	_Interface[0].h = BORDER_INTERFACE_1;

	_Interface[1].x = 0;
	_Interface[1].y = BORDER_INTERFACE_1;
	_Interface[1].w = BORDER_INTERFACE_5;
	_Interface[1].h = BORDER_INTERFACE_2 - BORDER_INTERFACE_1;

	_Interface[2].x = BORDER_INTERFACE_6;
	_Interface[2].y = BORDER_INTERFACE_1;
	_Interface[2].w = WIN_WIDTH - BORDER_INTERFACE_6;
	_Interface[2].h = BORDER_INTERFACE_2 - BORDER_INTERFACE_1;
		
	_Interface[3].x = 0;
	_Interface[3].y = BORDER_INTERFACE_2;
	_Interface[3].w = WIN_WIDTH;
	_Interface[3].h = BORDER_INTERFACE_3 - BORDER_INTERFACE_2;

	_Interface[4].x = 0;
	_Interface[4].y = BORDER_INTERFACE_3;
	_Interface[4].w = BORDER_INTERFACE_5;
	_Interface[4].h = BORDER_INTERFACE_4 - BORDER_INTERFACE_1;

	_Interface[5].x = BORDER_INTERFACE_6;
	_Interface[5].y = BORDER_INTERFACE_3;
	_Interface[5].w = WIN_WIDTH - BORDER_INTERFACE_6;
	_Interface[5].h = BORDER_INTERFACE_2 - BORDER_INTERFACE_1;

	_Interface[6].x = 0;
	_Interface[6].y = WIN_HEIGHT - BORDER_INTERFACE_4;
	_Interface[6].w = WIN_WIDTH;
	_Interface[6].h = WIN_HEIGHT - BORDER_INTERFACE_4;

	_Interface[7].x = BORDER_INTERFACE_5;
	_Interface[7].y = BORDER_INTERFACE_1;
	_Interface[7].w = BORDER_INTERFACE_6 - BORDER_INTERFACE_5;
	_Interface[7].h = BORDER_INTERFACE_2 - BORDER_INTERFACE_1;

	_Interface[8].x = BORDER_INTERFACE_5;
	_Interface[8].y = BORDER_INTERFACE_3;
	_Interface[8].w = BORDER_INTERFACE_6 - BORDER_INTERFACE_5;
	_Interface[8].h = BORDER_INTERFACE_4 - BORDER_INTERFACE_3;
}

int ss::View::draw_interface(SDL_Renderer *_rd) {
	auto r = INIT;
	
	for (int i = 0; i < 9; ++i) {
		r = SDL_SetRenderDrawColor(_rd, COLOR_FRAME_R, COLOR_FRAME_G, COLOR_FRAME_B, COLOR_FRAME_A);
		SDL_RenderFillRect(_rd, &_Interface[i]);
	}

	//SDL_Rect rct = {MARGIN_FRAME_LEFT,MARGIN_FRAME_TOP,(MARGIN_FRAME_RIGHT-MARGIN_FRAME_LEFT),(MARGIN_FRAME_MIDDLE-MARGIN_FRAME_TOP)};
	//SDL_RenderFillRect(_rd, &rct);

	//r = SDL_SetRenderDrawColor(_rd, 255, 255, 255, COLOR_FRAME_A);
	//rct.x = MARGIN_FRAME_LEFT;
	//rct.y = MARGIN_FRAME_MIDDLE_TOP;
	//rct.w = MARGIN_FRAME_RIGHT - MARGIN_FRAME_LEFT;
	//rct.h = (int)((WIN_HEIGHT - MARGIN_FRAME_MIDDLE_TOP) * .85);
	//SDL_RenderFillRect(_rd, &rct);

	return OK;
}

//int ss::View::set_color_bg(SDL_Renderer* _rd, int _r, int _g, int _b, int _a) {
//	if (!(
//		(_r >= 0 && _r < 256) && (_g >= 0 && _g < 256) &&
//		(_b >= 0 && _b < 256) && (_a >= 0 || _a < 256))
//		) return OUT_OF_BOUNDS_PARAMETER;
//
//	auto r =	SDL_RenderClear(_rd);
//	r =			SDL_SetRenderDrawColor(_rd, _r, _g, _b, _a);
//				SDL_RenderPresent(_rd);
//
//	return OK;
//}
//
//int ss::View::set_color_bg(SDL_Renderer* _rd, SDL_Color _c) {
//	if (!(
//		(_c.r >= 0 && _c.r < 256) && (_c.g >= 0 && _c.g < 256) &&
//		(_c.b >= 0 && _c.b < 256) && (_c.a >= 0 || _c.a < 256))
//		) return OUT_OF_BOUNDS_PARAMETER;
//
//	auto r =	SDL_RenderClear(_rd);
//	r =			SDL_SetRenderDrawColor(_rd, _c.r, _c.g, _c.b, _c.a);
//				SDL_RenderPresent(_rd);
//	return OK;
//}

