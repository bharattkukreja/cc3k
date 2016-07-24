#include "textui.h"

using namespace std;

TextUI::TextUI(istream &in = cin, ostream &out = cout) :
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
                unique_ptr<Sprite> s = single_cell.sprite;
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
    } 

    out << endl;
    out << "Race: " << hero.getType() << " " << "Gold: " << hero.score();
    for(int i = 0; i < 30; i++)
        out << " ";
    out << g.getFloorCount() << endl;
    out << "HP: " << hero.hp << endl;
    out << "Atk: " << hero.atk << endl;
    out << "Def: " << hero.def << endl;
    out << "Action: " << endl; 

}

void TextUI::output_message(string s) {
    out << s << endl;
}





