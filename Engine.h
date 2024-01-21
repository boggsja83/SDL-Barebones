#pragma once

#include "Settings.h"

#include "Game.h"
#include "View.h"
#include "Input.h"
//#include "ICMap.h"

namespace ss
{
	class Engine
	{
    private:

        Game*   _Game;
        View*   _View;
        Input*  _Input;

        bool    _On;

        int     loop();
        int     input_to_context(int *);
        int     update(int*);
        int     render();

    public:
        Engine(Engine const& _eng)
        {
            this->_Game = _eng._Game;
            this->_View = _eng._View;
            this->_Input = _eng._Input;
            this->_On = _eng._On;
            this->_FrameCount = _eng._FrameCount;
        }
        Engine():_Game(nullptr),_View(nullptr),_Input(nullptr),_On(false),_FrameCount(0){}
        ~Engine() 
        {
            delete _Game;
            delete _View;
            delete _Input;

            SDL_Quit();
        }

        int             init();

        inline int      start() { _On = true; return loop(); }
        inline void     stop() { _On = false; }
        inline void     log(char const *_c) { std::cout << _c; }

        int             _FrameCount;

	};
}

