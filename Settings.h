#pragma once

#include <iostream>
#include <typeinfo>

//#include "RT.h"

namespace ss
{
	//	GENERAL - settings
constexpr auto	INIT =					-1;

	//	VIEW - settings
constexpr auto	WIN_WIDTH =				960;
constexpr auto	WIN_HEIGHT =			720;

constexpr auto	BORDER_INTERFACE_1 = static_cast<int>(WIN_HEIGHT * .05);
constexpr auto	BORDER_INTERFACE_2 = static_cast<int>(WIN_HEIGHT * .9);
constexpr auto	BORDER_INTERFACE_3 = static_cast<int>(BORDER_INTERFACE_2 + (WIN_HEIGHT - BORDER_INTERFACE_2) * .025);
constexpr auto	BORDER_INTERFACE_4 = static_cast<int>(WIN_HEIGHT * .975);
constexpr auto	BORDER_INTERFACE_5 = static_cast<int>(WIN_WIDTH * .025);
constexpr auto	BORDER_INTERFACE_6 = static_cast<int>(WIN_WIDTH * .975);

//constexpr auto	MARGIN_FRAME_TOP =		(int)(WIN_HEIGHT * .05);	//	row
//constexpr auto	MARGIN_FRAME_BOTTOM =	(int)(WIN_HEIGHT * .95);	//	row
//constexpr auto	MARGIN_FRAME_MIDDLE =	(int)(WIN_HEIGHT * .9);		//	row
//constexpr auto	MARGIN_FRAME_MIDDLE_TOP=(int)((WIN_HEIGHT - MARGIN_FRAME_MIDDLE)*.15)+ MARGIN_FRAME_MIDDLE;	//	row
//constexpr auto	MARGIN_FRAME_LEFT =		(int)(WIN_WIDTH * .025);	//	col
//constexpr auto	MARGIN_FRAME_RIGHT =	(int)(WIN_WIDTH * .975);	//	col

constexpr auto	COLOR_BG_R =			102;
constexpr auto	COLOR_BG_G =			204;
constexpr auto	COLOR_BG_B =			255;
constexpr auto	COLOR_BG_A =			255;

constexpr auto	COLOR_FRAME_R =			0;
constexpr auto	COLOR_FRAME_G =			0;
constexpr auto	COLOR_FRAME_B =			0;
constexpr auto	COLOR_FRAME_A =			255;

	//	INPUT - settings
constexpr auto	KEY_COUNT =				7;	//	default key bindings
constexpr auto	KEY_ESC =				41;	//	SDL scan scodes
constexpr auto	KEY_RET =				40;
constexpr auto	KEY_SPACE =				44;
constexpr auto	KEY_W =					26;
constexpr auto	KEY_A =					4;
constexpr auto	KEY_S =					22;
constexpr auto	KEY_D =					7;

	//	GAME - settings
constexpr auto	GAME_TITLE =			"Game Of Liff";

constexpr auto	CONTEXT_COUNT =			1; //	player
constexpr auto	CONTEXT_ID_PLAYER =		0;

constexpr auto	CONTEXT_OPERATIONS_COUNT =	6;
constexpr auto	CURSOR_UP_CONTEXT =		KEY_W;		//	default key mappings
constexpr auto	CURSOR_DOWN_CONTEXT =	KEY_S;
constexpr auto	CURSOR_LEFT_CONTEXT =	KEY_A;
constexpr auto	CURSOR_RIGHT_CONTEXT =	KEY_D;
constexpr auto	CURSOR_SELECT_CONTEXT =	KEY_SPACE;
constexpr auto	EXIT_GAME_CONTEXT =		KEY_ESC;

	//	ENGINE - settings
constexpr auto	FPS =					30;
constexpr auto  FRAME_TARGET_TIME =		1000 / FPS;	// milliseconds


	//	GENERAL return codes
constexpr auto	OK =					0;
constexpr auto	FAIL_UNKNOWN =			-666;
constexpr auto	OUT_OF_BOUNDS_PARAMETER = -5;

	//	100s - ENGINE return codes
constexpr auto	EXIT_LOOP =				101;
constexpr auto	FAIL_CREATE_COMPONENT = 102;

	//	200s - VIEW return codes
constexpr auto	FAIL_CREATE_WIN =		201;
constexpr auto	FAIL_CREATE_REND =		202;

	//	300s - MODEL return codes

	//	400s - INPUT return codes
constexpr auto	INPUT_NONE =			401;





}

