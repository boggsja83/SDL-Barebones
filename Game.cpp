#include "Game.h"

int ss::Game::init()
{
	_Context[0] = CURSOR_UP;
	_Context[1] = CURSOR_DOWN;
	_Context[2] = CURSOR_LEFT;
	_Context[3] = CURSOR_RIGHT;
	_Context[4] = CURSOR_SELECT;
	_Context[5] = EXIT_GAME;

	return OK;
}
