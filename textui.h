#ifndef __TEXTUI_H__
#define __TEXTUI_H__
#include "ui.h"
#include <iostream>
#include <string>
#include <memory>

class TextUI : public UI {
    std::istream &in;
    std::ostream &out;
    std::vector <std::vector <char>> file_vector;

    public:
        TextUI(std::istream &in = std::cin, std::ostream &out = std::cout);
        CommandType getNextInput() override;
        void read_file(std::string file) override;
        bool read_floor(std::vector <std::vector <CellType>> &layout, std::map <std::pair <int, int>, std::shared_ptr<Sprite>> &sprite_coords) override;
        void output(std::vector <std::vector <Cell>> grid) override;
        void display_commands() override;
        std::string convert(SpriteType s) override;
        void output_message(std::string s) override;
        void output_number(int n) override;
        void newline() override;
};

#endif
