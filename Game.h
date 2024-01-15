#pragma once

#include "Settings.h"

namespace ss{
	class Game{
	private:
	public:
		Game(): _Context() {}
		Game(Game const& _g){ 
			for (auto i = 0; i < CONTEXT_OPERATIONS_COUNT; ++i)
				this->_Context[i] = _g._Context[i];
		}
		~Game() {}

		int init();
		int	update(int*, int);
		int process_input(int);

		int		_Context[CONTEXT_OPERATIONS_COUNT];
	};
}
                                                                                