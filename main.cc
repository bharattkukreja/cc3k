#include "gamehandler.h"
#include "gamemap.h"
#include "ui.h"
#include <iostream>
#include <cstdlib>

int main(int argc, const char *argv[])
{
    GameMap g;
    UI ui;
    GameHandler gh(g, ui);
    if(argc < 2) {
        std::cout << "Please provide the floor layout" << std::endl;
        exit(0);
    }
    gh.play(argv[1]);
}
