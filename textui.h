#ifndef __TEXTUI_H__
#define __TEXTUI_H__
#include "ui.h"
#include <iostream>
#include <string>

class TextUI : public UI {
    std::istream &in;
    std::ostream &out;
    
    public:
        TextUI(std::istream &in = std::cin, std::ostream &out = std::cout);
        CommandType getNextInput() override;
        void output(std::vector <std::vector <Cell>> grid) override;
        std::string convert(SpriteType s) override;
        void output_message(std::string s) override;
        void output_number(int n) override;
        void newline() override;
};

#endif
