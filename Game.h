#pragma once

#include "Settings.h"
#include "GameInputContext.h"

namespace ss{
	class Game{
	private:
	public:
		Game(): _Context() {}// : _ContextPlayer(), _ContextCurrent() {}
		Game(Game const& _g){ 
			//this->_ContextPlayer = _g._ContextPlayer;
			//this->_ContextCurrent = _g._ContextCurrent;
			for (auto i = 0; i < CONTEXT_OPERATIONS_COUNT; ++i)
			{ this->_Context[i] = _g._Context[i];}
		}
		~Game() {}

		int init();

		int		_Context[CONTEXT_OPERATIONS_COUNT];
		//GameInputContext*	_ContextListCurrent;
		//int _szCLC;

		//GameInputContext	_ContextPlayer;
		//GameInputContext*	_ContextCurrent;
		//GameInputContext	_ContextMenuMain;
	};
}
                                                                                