#pragma once

#include <iostream>

#include "RT.h"

namespace ss
{
	//	VIEW
constexpr auto	WIN_WIDTH =		640;
constexpr auto	WIN_HEIGHT =	480;

	//	GAME
constexpr auto	GAME_TITLE =	"Game Of Liff";

	//	ENGINE
constexpr auto	FPS =			30;
constexpr auto  FRAME_TARGET_TIME = 1000 / FPS;	// milliseconds

	//	INPUT
constexpr auto	KEYS_COUNT =	7;
constexpr auto	ESC	=			0;
constexpr auto	RET =			1;
constexpr auto	SPACE =			2;
constexpr auto	W =				3;
constexpr auto	A =				4;
constexpr auto	S =				5;
constexpr auto	D =				6;

}

