#include "Game.h"


int ss::Game::init()
{
	_Context[0] = CURSOR_UP_CONTEXT;
	_Context[1] = CURSOR_DOWN_CONTEXT;
	_Context[2] = CURSOR_LEFT_CONTEXT;
	_Context[3] = CURSOR_RIGHT_CONTEXT;
	_Context[4] = CURSOR_SELECT_CONTEXT;
	_Context[5] = EXIT_GAME_CONTEXT;

	_Rows = DEFAULT_ROWS;
	_Cols = DEFAULT_COLS;

	return OK;
}

void ss::Game::init_copy(Game const& _g) {

	for (auto i = 0; i < CONTEXT_OPERATIONS_COUNT; ++i)
		this->_Context[i] = _g._Context[i];

	this->_Rows = _g._Rows;
	this->_Cols = _g._Cols;
}

//	_c is an array of CONTEXT_OPERATIONS where keyboard button is pressed
//	obtained from Engine::input_to_context()
//	this class supplies current context options per _Context
int ss::Game::update(int* _c,int _sz) {
	auto r = INIT;

	for (int i = 0; i < _sz; ++i) {
		r = process_input(_c[i]);
		if (r == EXIT_LOOP) break;
	}
	
	if (_sz == 0)return OK;
	// currently, only returns r for last element in array.  TODO return array of r's??
	return r;
}

int ss::Game::process_input(int _c) {
	switch (_c) {
	case CURSOR_UP_CONTEXT:
		std::cout << "CURSOR_UP\n";
		break;
	case CURSOR_DOWN_CONTEXT:
		std::cout << "CURSOR_DOWN\n";
		break;
	case CURSOR_LEFT_CONTEXT:
		std::cout << "CURSOR_LEFT\n";
		break;
	case CURSOR_RIGHT_CONTEXT:
		std::cout << "CURSOR_RIGHT\n";
		break;
	case CURSOR_SELECT_CONTEXT:
		std::cout << "CURSOR_SELECT\n";
		return CURSOR_SELECT_CONTEXT;
		break;
	case EXIT_GAME_CONTEXT:
		std::cout << "EXIT_GAME\n";
		return EXIT_LOOP;
		break;
	default:
		break;
	}
	return OK;
}
