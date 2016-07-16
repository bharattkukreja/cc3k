#ifndef __UI_H__
#define __UI_H__
#include "ui.h"
#include "commands.h"
#include "cell.h"
#include "vector.h"


class UI {
    public:
        CommandType getNextInput();
        void output(std::vector <std::vector <Cell>>);
}

#endif


