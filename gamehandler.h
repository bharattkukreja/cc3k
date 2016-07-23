#ifndef __GAMEHANDLER_H__
#define __GAMEHANDLER_H__
#include <string>
#include <memory>
#include "pc.h"

class GameMap;
class UI;

class GameHandler {
    GameMap &g;
    UI &ui;
    std::unique_ptr<PC> hero;

    public:
        void play(std::string file);
        GameHandler(GameMap &g, UI &ui);
};



#endif
