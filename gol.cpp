#include "Engine.h"

int main(int argc, char* argv[])
{
    ss::Engine* eng = new ss::Engine();
 
    auto r = eng->init();
    switch (r)
    {
    case ss::OK:
        eng->start();
        break;
    case ss::FAIL_CREATE_COMPONENT:
    case ss::FAIL_CREATE_WIN:
    case ss::FAIL_CREATE_REND:
    case ss::FAIL_UNKNOWN:
        delete eng;
        return r;
    default:
        delete eng;
        return ss::FAIL_UNKNOWN;
    }

    //if (!r) { eng->start(); }

    delete eng;

    return 0;
}
