#pragma once

#include <iostream>

//#include "RT.h"

namespace ss
{
	//	GENERAL - settings
constexpr auto	INIT					= -1;
constexpr auto	DEFAULT_ROWS			= 25;
constexpr auto	DEFAULT_COLS			= 25;

	//	VIEW - settings
constexpr float	DEFAULT_WIN_WIDTH		= 720;
constexpr float	DEFAULT_WIN_HEIGHT		= 720;

constexpr auto	COLOR_BG_R				= 102;
constexpr auto	COLOR_BG_G				= 204;
constexpr auto	COLOR_BG_B				= 255;
constexpr auto	COLOR_BG_A				= 255;

constexpr auto	COLOR_FRAME_R			= 0;
constexpr auto	COLOR_FRAME_G			= 0;
constexpr auto	COLOR_FRAME_B			= 0;
constexpr auto	COLOR_FRAME_A			= 255;

constexpr auto	COLOR_GRID_R			= 255;
constexpr auto	COLOR_GRID_G			= 255;
constexpr auto	COLOR_GRID_B			= 255;
constexpr auto	COLOR_GRID_A			= 255;

	//	INPUT - settings
constexpr auto	KEY_COUNT				= 7;	//	default key bindings
constexpr auto	KEY_ESC					= 41;	//	SDL scan scodes
constexpr auto	KEY_RET					= 40;
constexpr auto	KEY_SPACE				= 44;
constexpr auto	KEY_W					= 26;
constexpr auto	KEY_A					= 4;
constexpr auto	KEY_S					= 22;
constexpr auto	KEY_D					= 7;

	//	GAME - settings
constexpr auto	GAME_TITLE =			"Game Of Liff";

constexpr auto	CONTEXT_COUNT			= 1; //	player
constexpr auto	CONTEXT_ID_PLAYER		= 0;

constexpr auto	CONTEXT_OPERATIONS_COUNT = 6;
constexpr auto	CURSOR_UP_CONTEXT		= KEY_W;		//	default key mappings
constexpr auto	CURSOR_DOWN_CONTEXT		= KEY_S;
constexpr auto	CURSOR_LEFT_CONTEXT		= KEY_A;
constexpr auto	CURSOR_RIGHT_CONTEXT	= KEY_D;
constexpr auto	CURSOR_SELECT_CONTEXT	= KEY_SPACE;
constexpr auto	EXIT_GAME_CONTEXT		= KEY_ESC;

	//	ENGINE - settings
constexpr auto	FPS						= 30;
constexpr auto  FRAME_TARGET_TIME		= 1000 / FPS;	// milliseconds

/**********************************************************************************/

	//	GENERAL return codes
constexpr auto	OK						= 0;
constexpr auto	FAIL_UNKNOWN			= -666;
constexpr auto	OUT_OF_BOUNDS_PARAMETER = -5;

	//	100s - ENGINE return codes
constexpr auto	EXIT_LOOP				= 101;
constexpr auto	FAIL_CREATE_COMPONENT	= 102;

	//	200s - VIEW return codes
constexpr auto	FAIL_CREATE_WIN			= 201;
constexpr auto	FAIL_CREATE_REND		= 202;
constexpr auto	FAIL_SET_DRAW_COLOR		= 203;
constexpr auto	FAIL_DRAW_LINE			= 204;
constexpr auto	FAIL_FILL_RECT			= 205;
constexpr auto	FAIL_RENDER_CLEAR		= 206;

	//	300s - GAME return codes

	//	400s - INPUT return codes
constexpr auto	INPUT_NONE				= 401;
constexpr auto	RESIZE_WINDOW			= 402;




}

