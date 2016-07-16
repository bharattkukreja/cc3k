#ifndef __TEXTUI_H__
#define __TEXTUI_H__
#include "ui.h"

class TextUI : public UI {
    public:
        CommandType getNextInput() override;
        void output(vector <vector <Cell>>) override;
}

#endif
