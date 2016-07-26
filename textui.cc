#include "textui.h"
#include "sprite.h"
#include "spritetype.h"
#include <fstream>
#include <sstream>
#include "human.h"
#include "stairs.h"
#include "vampire.h"
#include "goblin.h"
#include "phoenix.h"
#include "troll.h"
#include "merchant.h"
#include "werewolf.h"
#include "dragon.h"
#include "hppot.h"
#include "atkpot.h"
#include "defpot.h"
#include "gold.h"

using namespace std;

TextUI::TextUI(istream &in, ostream &out) :
    in {in}, out {out} {}

CommandType TextUI::getNextInput() {
    CommandType command;
    string s;
    in >> s;
    if(in.eof())
        exit(0);

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
    else if(s == "o")
        command = CommandType::o;
    else if(s == "y")
        command =  CommandType::y;
    else
        command = CommandType::n;

    return command;
}

void TextUI::read_file(string file) {
    ifstream fin(file);
    while(!fin.eof()) {
        string line;
        getline(fin, line);
        istringstream iss(line);
        char ch;
        vector <char> temp;
         
        while(iss >> noskipws >> ch) {
            temp.emplace_back(ch);
        }

        if(temp.size() != 0)
            file_vector.emplace_back(temp);
    }
}

bool TextUI::read_floor(vector <vector <CellType>> &layout, map <pair <int, int>, shared_ptr <Sprite>> &sprite_coords) {

    bool empty_map = true;
    for (unsigned int row = 0; row < 25; row++) {
        
        vector <CellType> temp;

        for (unsigned int col = 0; col < file_vector[row].size(); col++) {
            char ch = file_vector[row][col];
        
            CellType c_type;
            shared_ptr <Sprite> sprite = nullptr;
            
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
            else {
                empty_map = false;
                c_type = CellType::Floor;

                if(ch == '@') 
                   sprite = shared_ptr<Human>(new Human());
                
                else if(ch == '\\')
                    sprite = shared_ptr<Stairs>(new Stairs());
                    
                else if(ch == 'V')
                    sprite = shared_ptr<Vampire>(new Vampire());

                else if(ch == 'W')
                    sprite = shared_ptr<Werewolf>(new Werewolf());

                else if(ch == 'N')
                    sprite = shared_ptr<Goblin>(new Goblin());

                else if(ch == 'M')
                    sprite = shared_ptr<Merchant>(new Merchant());

                else if(ch == 'D')
                    sprite = shared_ptr<Dragon>(new Dragon());

                else if(ch == 'X')
                    sprite = shared_ptr<Phoenix>(new Phoenix());

                else if(ch == 'T')
                    sprite = shared_ptr<Troll>(new Troll());

                else if(ch == '0')
                    sprite = shared_ptr<HPPot>(new HPPot(true));

                else if(ch == '1')
                    sprite = shared_ptr<AtkPot>(new AtkPot(true));

                else if(ch == '2')
                    sprite = shared_ptr<DefPot>(new DefPot(true));

                else if(ch == '3')
                    sprite = shared_ptr<HPPot>(new HPPot(false));

                else if(ch == '4')
                    sprite = shared_ptr<AtkPot>(new AtkPot(false));
                
                else if(ch == '5') 
                    sprite = shared_ptr<DefPot>(new DefPot(false));

                else if(ch == '6')
                    sprite = shared_ptr<Gold>(new Gold(1));

                else if(ch == '7')
                    sprite = shared_ptr<Gold>(new Gold(2));

                else if(ch == '8')
                    sprite = shared_ptr<Gold>(new Gold(4));
                else 
                    sprite = shared_ptr<Gold>(new Gold(6));

                sprite_coords[make_pair(row, col)] = shared_ptr<Sprite>(sprite);
            }

            temp.emplace_back(c_type);
        }
        
        layout.emplace_back(temp);

    }

    file_vector.erase(file_vector.begin(), file_vector.begin() + 25);
    return empty_map;
        
}


void TextUI::output(vector <vector <Cell>> grid) {
    for (auto row: grid) {
        for (auto single_cell: row) {
            CellType type = single_cell.getType();
            
            if(!single_cell.isEmpty()) {
                
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
                else if(sprite_type == SpriteType::Dragon)
                    out << "D";
                else if(sprite_type == SpriteType::Stairs)
                    out << "\\";
                else if(sprite_type == SpriteType::AtkPot || sprite_type == SpriteType::DefPot || sprite_type == SpriteType::HPPot)
                    out << "P";
                else if(sprite_type == SpriteType::Gold)
                    out << "G";
            }

            else {

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
            }
        } 
        out << endl;
    } 

    out << endl;

}

string TextUI::convert_direction(CommandType input) {
    string direction = "";
    if(input == CommandType::no)
        direction = "north";
    else if(input == CommandType::so)
        direction = "south";
    else if(input == CommandType::ea)
        direction = "east";
    else if(input == CommandType::we)
        direction = "west";
    else if(input == CommandType::nw)
        direction = "north-west";
    else if(input == CommandType::ne)
        direction = "north-east";
    else if(input == CommandType::sw)
        direction = "south-west";
    else if(input == CommandType::se)
        direction = "south-east";

    return direction;
}

void TextUI::put_direction(string &action, string direction) {
    istringstream iss(action);
    ostringstream oss;
    string word;
    bool flag = false;
    while(iss >> word) {
        if(word == "and") {
            oss << direction;
            oss << " ";
            flag = true;
        }
        oss << word << " ";
    }
    
    if(!flag)
        action = action + " " + direction;
    else
        action = oss.str();
    
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


