#ifndef __UI_H__
#define __UI_H__
#include "ui.h"
#include "commands.h"
#include "cell.h"
#include <vector>
#include "spritetype.h"

class UI {
    public:
        virtual CommandType getNextInput() = 0;
        virtual void read_floor(std::string file, std::vector <std::vector <CellType>> &layout) = 0;
        virtual void output(std::vector <std::vector <Cell>> grid) = 0;
        
        virtual std::string convert(SpriteType s) = 0;
        virtual void output_message(std::string s) = 0;
        virtual void output_number(int n) = 0;
        virtual void newline() = 0;

        virtual ~UI() {

        }

};

#endif


