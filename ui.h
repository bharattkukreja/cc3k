#ifndef __UI_H__
#define __UI_H__
#include "ui.h"
<<<<<<< HEAD
#include "commands.h"
#include "cell.h"
=======
>>>>>>> 5803d250cb7534d7b0a2c8950775f7c31bba403b
#include "vector.h"


class UI {
    public:
        CommandType getNextInput();
        void output(std::vector <std::vector <Cell>>);
}

#endif


