#include "Engine.h"

int main(int argc, char** argv)
{
    ss::Engine* eng = new ss::Engine();
 
    auto r = eng->init();
    switch (r)
    {
    case ss::OK: 
        r = eng->start();
        break;
    case ss::FAIL_CREATE_COMPONENT:
    case ss::FAIL_CREATE_WIN:
    case ss::FAIL_CREATE_REND:
        break;
    default:
        r = ss::FAIL_UNKNOWN;
    }

    delete eng;

    std::cout << "r = ["<<r<<"]";
    return r;
}
