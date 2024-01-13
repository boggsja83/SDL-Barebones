#pragma once

#include <iostream>

#include "RT.h"

namespace ss
{
	//	VIEW
constexpr auto	WIN_WIDTH =		640;
constexpr auto	WIN_HEIGHT =	480;

	//	INPUT
constexpr auto	KEYS_COUNT = 7;
constexpr auto	ESC = 41;//SDL scan scodes
constexpr auto	RET = 40;
constexpr auto	SPACE = 44;
constexpr auto	W = 26;
constexpr auto	A = 4;
constexpr auto	S = 22;
constexpr auto	D = 7;

	//	GAME
constexpr auto	GAME_TITLE =	"Game Of Liff";

constexpr auto	CONTEXT_COUNT = 1; //	player
constexpr auto	CONTEXT_ID_PLAYER = 0;

constexpr auto	CONTEXT_OPERATIONS_COUNT = 6;
constexpr auto	CURSOR_UP = W;		//	default key bindings
constexpr auto	CURSOR_DOWN = S;
constexpr auto	CURSOR_LEFT = A;
constexpr auto	CURSOR_RIGHT = D;
constexpr auto	CURSOR_SELECT = SPACE;
constexpr auto	EXIT_GAME = ESC;

	//	ENGINE
constexpr auto	FPS =			30;
constexpr auto  FRAME_TARGET_TIME = 1000 / FPS;	// milliseconds



}

