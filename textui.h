#ifndef __TEXTUI_H__
#define __TEXTUI_H__
#include "ui.h"
#include <iostream>

class TextUI : public UI {
    istream &in;
    ostream &out;
    public:
        TextUI();
        CommandType getNextInput() override;
        void output(vector <vector <Cell>> grid) override;
        void output_message(string s) override;
}

#endif
