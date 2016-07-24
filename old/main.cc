#include "gamehandler.h"
#include <iostream>
#include <cstdlib>

int main(int argc, const char *argv[])
{
    GameHandler gh;
    if(argc < 2) {
        std::cout << "Please provide the floor layout" << std::endl;
        exit(0);
    }
    gh.play(argv[1]);
}
