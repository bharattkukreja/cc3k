#include "textui.h"
#include "sprite.h"
#include "spritetype.h"
#include <fstream>
#include <sstream>

using namespace std;

TextUI::TextUI(istream &in, ostream &out) :
    in {in}, out {out} {}

CommandType TextUI::getNextInput() {
    CommandType command;
    string s;
    in >> s;
    if(s == "no")
        command = CommandType::no;
    else if(s == "so")
        command = CommandType::so;
    else if(s == "ea")
        command = CommandType::ea;
    else if(s == "we")
        command = CommandType::we;
    else if(s == "ne")
        command = CommandType::ne;
    else if(s == "nw")
        command = CommandType::nw;
    else if(s == "se")
        command = CommandType::se;
    else if(s == "sw")
        command = CommandType::sw;
    else if(s == "u")
        command = CommandType::u;
    else if(s == "a")
        command = CommandType::a;
    else if(s == "h")
        command = CommandType::h;
    else if(s == "e")
        command = CommandType::e;
    else if(s == "d")
        command = CommandType::d;
    else if(s == "o")
        command = CommandType::o;
    else if(s == "r")
        command = CommandType::r;
    else if(s == "q")
        command = CommandType::q;
    else if(s == "h")
        command = CommandType::h;
    else if(s == "e")
        command = CommandType::e;
    else if(s == "d")
        command = CommandType::d;
    else
        command = CommandType::o;

    return command;
}

void TextUI::read_floor(string file, vector <vector <CellType>> &layout) {

    ifstream fin(file);

    while(!fin.eof()) {
        string line;
        getline(fin, line);
        istringstream iss(line);
        char ch;
        vector <CellType> temp;

        while(iss >> noskipws >> ch) {
            CellType c_type;

            if(ch == '|')
            c_type = CellType::Wall_vertical;
            else if(ch == '-')
                c_type = CellType::Wall_horizontal;
            else if(ch == '+')
                c_type = CellType::Door;
            else if(ch == '#')
                c_type = CellType::Passage;
            else if(ch == '.')
                c_type = CellType::Floor;
            else if(ch == ' ')
                c_type = CellType::Space;
            else
                break;

            temp.emplace_back(c_type);

        }

        layout.emplace_back(temp);
    }
}


void TextUI::output(vector <vector <Cell>> grid) {
    for (auto row: grid) {
        for (auto single_cell: row) {
            CellType type = single_cell.getType();
            
            if(type == CellType::Floor)
                out << ".";
            else if(type == CellType::Door)
                out << "+";
            else if(type == CellType::Passage)
                out << "#";
            else if(type == CellType::Wall_horizontal)
                out << "-";
            else if(type == CellType::Wall_vertical)
                out << "|";
            else if(type == CellType::Space)
                out << " ";
            else {
                shared_ptr<Sprite> s = single_cell.sprite;
                SpriteType sprite_type = s->getType();
                if(sprite_type == SpriteType::Human || sprite_type == SpriteType::Elf ||
                   sprite_type == SpriteType::Dwarf || sprite_type == SpriteType::Orc) {
                    out << "@";
                }
                else if(sprite_type == SpriteType::Vampire)
                    out << "V";
                else if(sprite_type == SpriteType::Werewolf)
                    out << "W";
                else if(sprite_type == SpriteType::Troll)
                    out << "T";
                else if(sprite_type == SpriteType::Goblin)
                    out << "N";
                else if(sprite_type == SpriteType::Merchant)
                    out << "M";
                else if(sprite_type == SpriteType::Phoenix)
                    out << "X";
                else
                    out << "D";
            }
        } 
        out << endl;
    } 

    out << endl;

}

void TextUI::display_commands() {
    out << "Enter a command" <<  endl;
    out << "Directions : North(no), South(so), East(ea), West(we), NorthEast(ne), NorthWest(nw), SouthEast(se), SouthWest(sw)" << endl;
    out << "Use potion : u < direction >" << endl;
    out << "Attack : a < direction >" << endl;
    out << "Restart : r" <<  endl;
    out << "Quit : q" << endl;
}

string TextUI::convert(SpriteType s) {
    string str;
    if(s == SpriteType::Human)
        str = "Human";
    else if(s == SpriteType::Elf)
        str = "Elf";
    else if(s == SpriteType::Dwarf)
        str = "Dwarf";
    else
        str = "Orc";

    return str;
}

void TextUI::output_message(string str) {
    out << str;
}

void TextUI::output_number(int n) {
    out << n;
}

void TextUI::newline() {
    out << endl;
}


