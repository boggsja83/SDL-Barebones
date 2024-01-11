#pragma once

namespace ss
{
	//	GENERAL return codes
	constexpr auto OK =					0;
	constexpr auto INIT =				-1;
	constexpr auto FAIL_UNKNOWN =		-2;

	//	100s - ENGINE return codes
	constexpr auto QUIT_LOOP =			101;
	constexpr auto FAIL_CREATE_COMPONENT = 102;

	//	200s - VIEW return codes
	constexpr auto FAIL_CREATE_WIN =	201;
	constexpr auto FAIL_CREATE_REND	=	202;

	//	300s - MODEL return codes

	//	400s - INPUT return codes
	constexpr auto INPUT_NONE =			401;
}


