#ifndef __UI_H__
#define __UI_H__
#include "ui.h"
#include "commands.h"
#include "cell.h"
#include <vector>
#include <map>
#include "spritetype.h"
#include <memory>

class UI {
    public:
        virtual CommandType getNextInput() = 0;
        virtual void read_file(std::string file) = 0;
        virtual bool read_floor(std::vector <std::vector <CellType>> &layout, std::map <std::pair <int, int>, std::shared_ptr<Sprite>> &sprite_coords) = 0;
        virtual void output(std::vector <std::vector <Cell>> grid) = 0;
        virtual void display_commands() = 0;
        virtual std::string convert_direction(CommandType input) = 0;
        virtual void put_direction(std::string &action, std::string direction) = 0;
        virtual std::string convert(SpriteType s) = 0;
        virtual void output_message(std::string s) = 0;
        virtual void output_number(int n) = 0;
        virtual void newline() = 0;

        virtual ~UI() {

        }

};

#endif


