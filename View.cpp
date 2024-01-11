#include "View.h"

int ss::View::init()
{
	//SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_EVERYTHING);

	winWidth = WIN_WIDTH;
	winHeight = WIN_HEIGHT;

	winMain = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!winMain) { return FAIL_CREATE_WIN; }

	renMain = SDL_CreateRenderer(winMain, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!winMain) { return FAIL_CREATE_REND; }

	return OK;
}


