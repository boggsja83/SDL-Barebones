#include "Engine.h"

int ss::Engine::init()
{
	int r = INIT;
	
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

int ss::Engine::loop()
{
	int r = INIT;

	while(_On)
	{
		r = _Input->set_keys_state();
		if (r == QUIT_LOOP) { stop(); }
		
		r = input_to_context();

		//update();
		//render();
	}

	return OK;
}

int ss::Engine::input_to_context()
{


	return OK;
}

