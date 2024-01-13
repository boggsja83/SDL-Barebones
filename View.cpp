#include "View.h"

int ss::View::init()
{
	//SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_EVERYTHING);

	_WinWidth = WIN_WIDTH;
	_WinHeight = WIN_HEIGHT;

	_WinMain = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!_WinMain) { return FAIL_CREATE_WIN; }

	_RenMain = SDL_CreateRenderer(_WinMain, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!_RenMain) { return FAIL_CREATE_REND; }

	return OK;
}


