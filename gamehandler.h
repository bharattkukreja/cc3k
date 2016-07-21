#ifndef __GAMEHANDLER_H__
#define __GAMEHANDLER_H__
#include "ui.h"
#include "gamemap.h"

class GameHandler {
    GameMap g;
    UI ui;
    std::unique_ptr<PC> hero;

    public:
        void play(std::string file);
};



#endif
