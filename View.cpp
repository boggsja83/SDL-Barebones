#include "View.h"

void ss::View::set_borders() {

	BORDER_INTERFACE_1 = _WinHeight * .05f;
	BORDER_INTERFACE_2 = _WinHeight * .9f;
	BORDER_INTERFACE_3 = (_WinHeight - BORDER_INTERFACE_2) * .13f + BORDER_INTERFACE_2;
	BORDER_INTERFACE_4 = _WinHeight * .988f;
	BORDER_INTERFACE_5 = _WinWidth * .025f;
	BORDER_INTERFACE_6 = _WinWidth * .975f;
}

void ss::View::set_interface_rects() {
	_Interface[0].x = 0;
	_Interface[0].y = 0;
	_Interface[0].w = _WinWidth;
	_Interface[0].h = BORDER_INTERFACE_1;

	_Interface[1].x = 0;
	_Interface[1].y = BORDER_INTERFACE_1;
	_Interface[1].w = BORDER_INTERFACE_5;
	_Interface[1].h = BORDER_INTERFACE_2 - BORDER_INTERFACE_1;

	_Interface[2].x = BORDER_INTERFACE_6;
	_Interface[2].y = BORDER_INTERFACE_1;
	_Interface[2].w = _WinWidth - BORDER_INTERFACE_6;
	_Interface[2].h = BORDER_INTERFACE_2 - BORDER_INTERFACE_1;

	_Interface[3].x = 0;
	_Interface[3].y = BORDER_INTERFACE_2;
	_Interface[3].w = _WinWidth;
	_Interface[3].h = BORDER_INTERFACE_3 - BORDER_INTERFACE_2;

	_Interface[4].x = 0;
	_Interface[4].y = BORDER_INTERFACE_3;
	_Interface[4].w = BORDER_INTERFACE_5;
	_Interface[4].h = BORDER_INTERFACE_4 - BORDER_INTERFACE_3;

	_Interface[5].x = BORDER_INTERFACE_6;
	_Interface[5].y = BORDER_INTERFACE_3;
	_Interface[5].w = _WinWidth - BORDER_INTERFACE_6;
	_Interface[5].h = BORDER_INTERFACE_4 - BORDER_INTERFACE_3;

	_Interface[6].x = 0;
	_Interface[6].y = BORDER_INTERFACE_4;
	_Interface[6].w = _WinWidth;
	_Interface[6].h = _WinHeight - BORDER_INTERFACE_4;

	_Interface[7].x = BORDER_INTERFACE_5;
	_Interface[7].y = BORDER_INTERFACE_1;
	_Interface[7].w = BORDER_INTERFACE_6 - BORDER_INTERFACE_5;
	_Interface[7].h = BORDER_INTERFACE_2 - BORDER_INTERFACE_1;

	_Interface[8].x = BORDER_INTERFACE_5;
	_Interface[8].y = BORDER_INTERFACE_3;
	_Interface[8].w = BORDER_INTERFACE_6 - BORDER_INTERFACE_5;
	_Interface[8].h = BORDER_INTERFACE_4 - BORDER_INTERFACE_3;
}

int ss::View::init(){
	SDL_Init(SDL_INIT_VIDEO);

	_WinWidth	= DEFAULT_WIN_WIDTH;
	_WinHeight	= DEFAULT_WIN_HEIGHT;

	_WinMain = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int)_WinWidth, (int)_WinHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);//SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE);
	if (!_WinMain) { return FAIL_CREATE_WIN; }

	_RenMain = SDL_CreateRenderer(_WinMain, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!_RenMain) { return FAIL_CREATE_REND; }

	set_borders();
	set_interface_rects();

	return OK;
}

void ss::View::init_copy(View const& _v) {
	this->_WinWidth	 =	_v._WinWidth;
	this->_WinHeight =	_v._WinHeight;
	this->_WinMain	 =	_v._WinMain;
	this->_RenMain	 =	_v._RenMain;

	for (int i = 0; i < 9; ++i) this->_Interface[i] = _v._Interface[i];

	BORDER_INTERFACE_1 = _v.BORDER_INTERFACE_1;
	BORDER_INTERFACE_2 = _v.BORDER_INTERFACE_2;
	BORDER_INTERFACE_3 = _v.BORDER_INTERFACE_3;
	BORDER_INTERFACE_4 = _v.BORDER_INTERFACE_4;
	BORDER_INTERFACE_5 = _v.BORDER_INTERFACE_5;
	BORDER_INTERFACE_6 = _v.BORDER_INTERFACE_6;
}

int ss::View::draw_interface(SDL_Renderer* _rd) const{
	RandomNum	rn;
	auto		r = INIT;
	
	bool temp_switch = true;

	if (temp_switch) {
		r = SDL_SetRenderDrawColor(_rd, rn.random_int(0, 255), rn.random_int(0, 255), rn.random_int(0, 255), 255);
		if (r) return FAIL_SET_DRAW_COLOR;
	}
	for (int i = 0; i < 9; ++i) {
		
		if (!temp_switch) {
			r = SDL_SetRenderDrawColor(_rd, rn.random_int(0, 255), rn.random_int(0, 255), rn.random_int(0, 255), 255);
			if (r) return FAIL_SET_DRAW_COLOR;
		}
		else if (i == 7) {
			r = SDL_SetRenderDrawColor(_rd, rn.random_int(0, 255), rn.random_int(0, 255), rn.random_int(0, 255), 255);
			if (r) return FAIL_SET_DRAW_COLOR;
		}

		r = SDL_RenderFillRectF(_rd, &_Interface[i]);
		if (r) return FAIL_FILL_RECT;
	}

	return OK;
}

int ss::View::draw_grid(SDL_Renderer* _rd,int _r, int _c) const {
	float w = _Interface[7].w	, h = _Interface[7].h;
	float x = _Interface[7].x	, y = _Interface[7].y;
	float spc = 0				, sz = (float)((_r-1)*(_c-1)*2);
	int r = INIT;

	SDL_FPoint t1{};
	SDL_FPoint t2{};

	if (_r < 0 || _c < 0) return OUT_OF_BOUNDS_PARAMETER;

	//std::cout << "iface-8: x="<<x<<" y="<<y<<" w="<<w<<" h="<<h<<"\n";

	r = SDL_SetRenderDrawColor(_rd, COLOR_GRID_R, COLOR_GRID_G, COLOR_GRID_B, COLOR_GRID_A);
	if (r) return FAIL_SET_DRAW_COLOR;

	if (_c == 0) spc = w - 1;
	else spc = w / _c;

	//std::cout << "spc=\'" << spc << "\'\n";

	for (int i = 1; i < _c; ++i) {
		t1.x = x + i * spc - 1;
		t1.y = y;

		//std::cout << "t1.x=" << t1.x << " t1.y=" << t1.y << "\n";

		t2.x = x + i * spc - 1;
		t2.y = y + h - 1;

		//std::cout << "t2.x=" << t2.x << " t2.y=" << t2.y << "\n";

		r = SDL_RenderDrawLineF(_rd, t1.x, t1.y, t2.x, t2.y);
		if (r) return FAIL_DRAW_LINE;
	}

	if (_r == 0) spc = h - 1;
	else spc = h / _r;

	//::cout << "spc=\'" <<spc<<"\'\n";

	for (int i = 1; i < _r; ++i) {
		t1.x = x;
		t1.y = y + i * spc - 1;

		//std::cout << "t1.x=" << t1.x << " t1.y=" << t1.y << "\n";

		t2.x = x + w - 1;
		t2.y = y + i * spc - 1;

		//std::cout << "t2.x=" << t2.x << " t2.y=" << t2.y << "\n";

		r = SDL_RenderDrawLineF(_rd, t1.x, t1.y, t2.x, t2.y);
		if (r) return FAIL_DRAW_LINE;
	}
	return OK;
}

int ss::View::draw_fine_borders(SDL_Renderer* _rd) const {
	float	w = _Interface[7].w, h = _Interface[7].h;
	float x = _Interface[7].x, y = _Interface[7].y;

	auto r = SDL_SetRenderDrawColor(_rd, 0, 0, 0, 255);
	if (r) return FAIL_SET_DRAW_COLOR;
	
	r = SDL_RenderDrawLineF(_rd, x, y, x + w - 1, y);	//top
	if (r) return FAIL_DRAW_LINE;
	r = SDL_RenderDrawLineF(_rd, x + w - 1, y, x + w - 1, y + h - 1);	//right
	if (r) return FAIL_DRAW_LINE;
	r = SDL_RenderDrawLineF(_rd, x, y + h - 1, x + w - 1, y + h - 1);	//bottom
	if (r) return FAIL_DRAW_LINE;
	r = SDL_RenderDrawLineF(_rd, x, y, x, y + h - 1);	//left
	if (r) return FAIL_DRAW_LINE;

	w = _Interface[8].w, h = _Interface[8].h;
	x = _Interface[8].x, y = _Interface[8].y;

	r = SDL_RenderDrawLineF(_rd, x, y, x + w - 1, y);	//top
	if (r) return FAIL_DRAW_LINE;
	r = SDL_RenderDrawLineF(_rd, x + w - 1, y, x + w - 1, y + h - 1);	//right
	if (r) return FAIL_DRAW_LINE;
	r = SDL_RenderDrawLineF(_rd, x, y + h - 1, x + w - 1, y + h - 1);	//bottom
	if (r) return FAIL_DRAW_LINE;
	r = SDL_RenderDrawLineF(_rd, x, y, x, y + h - 1);	//left
	if (r) return FAIL_DRAW_LINE;

	return OK;
}


