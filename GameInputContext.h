#pragma once

namespace ss
{
	typedef struct GameInputContext
	{
		int*	lst;
		int		sz;
		int		id;

		GameInputContext():lst(nullptr),sz(-1),id(-1) {}
		GameInputContext(GameInputContext const& _gc) { this->lst = _gc.lst; this->sz = _gc.sz; this->id = _gc.id;
		}
		~GameInputContext() {}



	}GameInputContext;

}

