#ifndef __UI_H__
#define __UI_H__
#include "ui.h"
#include "commands.h"
#include "cell.h"
#include <vector>


class UI {
    public:
        CommandType getNextInput();
        void output(std::vector <std::vector <Cell>> grid);

        void output_message(std::string s);
};

#endif


