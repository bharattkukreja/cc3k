#include "gamehandler.h"
#include "ui.h"
#include "gamemap.h"
#include "pc.h"

using namespace std;

GameHandler::GameHandler(GameMap &g, UI &ui) : g{g}, ui{ui} {}

void GameHandler::play(string file) {
    
    ui.output_message("Enter the character you want to play with");
    CommandType c = ui.getNextInput();
    if(c == CommandType::h)
        hero = new Human();
    else if(c == CommandType::e)
        hero = new Elf();
    else if(c == CommandType::d)
        hero = new Dwarf();
    else
        hero = new Orc();
    
    vector <vector <CellType>> layout;
    
    ifstream fin(file);
    
    while(!fin.eof()) {
        string line;
        getline(fin, line);
        istringstream iss(line);
        char ch;
        vector <CellType> temp;

        while(iss >> ch) {
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

    g.setUpMap(layout);
    g.initialize(hero);
    
    while(true) {
        pair <CommandType CommandType> command_pair;
        CommandType input1 = CommandType::no_value;
        CommandType input2 = ui.getNextInput();
        if(input2 == CommandType::a || input2 == CommandType::d) {
            input1 = ui.getNextInput();
        }       
        else if(input2 == CommandType::r) {
            delete hero;
            ui.output_message("Restarting the game");
            play();
        }
        else if(input2 == CommandType::q) {
            delete hero;
            ui.output_message("Thanks for playing the game");
            break;
        }
        else if(g.getFloorCount() > 5) {
            delete hero;
            ui.output_message("You Won! Congratulations!");
            break;
        }
        else if(hero.hp == 0) {
            delete hero;
            ui.output_message("You Lost!");
            break;
        }
        
        ui.output(g.getGrid());
        command_pair = make_pair(input1, input2);
        g.nextTurn(command_pair);
    }

}



