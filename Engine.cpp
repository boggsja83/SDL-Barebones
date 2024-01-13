#include "Engine.h"

int ss::Engine::init(){
	auto r = INIT;
	
	_On = false;

	_Game = new Game;
	_View = new View;
	_Input = new Input;
	if (!(_Game && _View && _Input)) return FAIL_CREATE_COMPONENT;

	r = _Game->init();
	if (r != OK) { return r; }

	r = _View->init();
	if (r != OK) { return r; }

	r = _Input->init();
	if (r != OK) { return r; }

	return OK;
}

int ss::Engine::loop(){
	auto	r = INIT;
	int		clst[CONTEXT_OPERATIONS_COUNT];

	while(_On){
		r = _Input->set_keys_state();
		if (r == EXIT_LOOP) { stop(); }
		
		r = input_to_context(clst);
		
		//update();
		//render();
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

	return OK;
}

