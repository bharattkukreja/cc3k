#ifndef __UI_H__
#define __UI_H__
#include "ui.h"
#include "commands.h"
#include "cell.h"
#include <vector>
#include "spritetype.h"

class UI {
    public:
        CommandType getNextInput();
        void output(std::vector <std::vector <Cell>> grid);
        
        std::string convert(SpriteType s);
        void output_message(std::string s);
        void output_number(int n);
        void newline();

};

#endif


