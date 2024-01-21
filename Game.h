#pragma once

#include "Settings.h"

namespace ss{
	class Game{
	private:
	public:
		Game(): _Context(), _Rows(), _Cols() {}
		Game(Game const& _g) { init_copy(_g); }
		~Game() {}

		int init();
		void init_copy(Game const&);
		int	update(int*, int);
		int process_input(int);

		int	_Context[CONTEXT_OPERATIONS_COUNT];
		int	_Rows;
		int	_Cols;
	};
}
                                                                                