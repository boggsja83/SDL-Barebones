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

	while(_On){
		r = _Input->set_keys_state();
		if (r == EXIT_LOOP) stop();	//	handle system exit event [non-user]
		
		r = update(clst);
		if (r == EXIT_LOOP) stop(); //	handle exit event [user]

		r = render();
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
	SDL_Renderer* tr = _View->ren();
	auto r = INIT;
	//	draw background
	r = SDL_SetRenderDrawColor(tr, COLOR_BG_R, COLOR_BG_G, COLOR_BG_B, COLOR_BG_A);
	r = SDL_RenderClear(tr);
	
	r = _View->draw_interface(tr);

	SDL_RenderPresent(tr);




	return OK;
}

int ss::Engine::random_int(int _lo, int _hi) {

	return OK;
}

