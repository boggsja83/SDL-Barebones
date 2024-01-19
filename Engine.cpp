#include "Engine.h"

int ss::Engine::init(){
	auto r = INIT;
	
	_On = false;

	_Game = new Game;
	_View = new View;
	_Input = new Input;
	if (!(_Game && _View && _Input)) return FAIL_CREATE_COMPONENT;

	r = _Game->init();	if (r != OK) return r;
	r = _View->init();	if (r != OK) return r;
	r = _Input->init();	if (r != OK) return r;

	return OK;
}

int ss::Engine::loop(){
	auto	r = INIT;
	int		clst[CONTEXT_OPERATIONS_COUNT];
	int		w = 0, h = 0;
	bool	pause = true;

	while(_On){
		++_FrameCount;

		r = _Input->poll_events();
		switch (r){
		case OK:
			break;
		case EXIT_LOOP:
			stop();
			break;
		case RESIZE_WINDOW:
			SDL_GetWindowSize(_View->win(), &w, &h);
			_View->set_win_width(w);
			_View->set_win_height(h);
			_FrameCount = 0;
			break;
		default:
			return r;
		}

		r = update(clst);
		switch (r) {
		case OK:
			break;
		case EXIT_LOOP:
			stop();
			break;
		case CURSOR_SELECT_CONTEXT:
			_FrameCount = 0;
			break;
		default:
			return r;
		}

		r = render();
		switch (r) {
		case OK:
			break;
		default:
			return r;
		}
	}

	return OK;
}

//	_c requires an empty array sized CONTEXT_OPERATIONS_COUNT
//	function returns number of _c entries; capacity is unchanged
int ss::Engine::input_to_context(int *_c){
	SDL_KeyboardEvent*	keys	= _Input->_Keys;
	int*				context = _Game->_Context;

	SDL_KeyboardEvent	tk;
	auto				tsz = 0;

	for (auto i = 0; i < CONTEXT_OPERATIONS_COUNT; ++i)	{
		tk = keys[context[i]];
		if (tk.state == SDL_PRESSED)_c[tsz++] = context[i];
	}

	return tsz;
}

int ss::Engine::update(int* _c)
{
	auto r = input_to_context(_c);
	r = _Game->update(_c,r);

	return r;
}

int ss::Engine::render(){
	SDL_Renderer*	_rd = _View->ren();
	auto			r = INIT;

	if (_FrameCount == 1) {
		r = SDL_SetRenderDrawColor(_rd, COLOR_BG_R, COLOR_BG_G, COLOR_BG_B, COLOR_BG_A);
		if (r) return FAIL_SET_DRAW_COLOR;

		r = SDL_RenderClear(_rd);
		if (r) return FAIL_RENDER_CLEAR;

		r = _View->draw_interface(_rd);
		if (r) return r;

		r = _View->draw_grid(_rd, 3, 3);
		if (r) return r;
	}

	SDL_RenderPresent(_rd);

	return OK;
}

