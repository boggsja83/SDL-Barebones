#pragma once

#include "Settings.h"

namespace ss
{
	class Game
	{
	private:
	public:
		Game() {}
		Game(Game const& _g) {}
		~Game() {}

		int init();
	};
}