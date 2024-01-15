#pragma once

#include "Settings.h"

namespace ss{
	class ICMap{
	private:
	public:
		ICMap(): _Map() {}
		ICMap(ICMap const& _m){
			for (int i = 0; i < KEY_COUNT; ++i) { this->_Map[i] = _m._Map[i]; }
		}
		~ICMap() {}

		int		_Map[KEY_COUNT];
	};

}
