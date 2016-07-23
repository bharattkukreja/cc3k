#ifndef __TEXTUI_H__
#define __TEXTUI_H__
#include "ui.h"
#include <iostream>
#include <string>

class TextUI : public UI {
    std::istream &in;
    std::ostream &out;
    
    public:
        TextUI(std::istream &in, std::ostream &out);
        CommandType getNextInput();
        void output(std::vector <std::vector <Cell>> grid);
        std::string convert(SpriteType s);
        void output_message(std::string s);
        void output_number(int n);
        void newline();
};

#endif
