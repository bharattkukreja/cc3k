#include "gamehandler.h"
#include "ui.h"
#include "gamemap.h"
#include "pc.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "orc.h"

#include <utility>
#include <iostream>             // to be deleted

using namespace std;

GameHandler::GameHandler(GameMap &g, UI &ui) : g{g}, ui{ui} {}

void GameHandler::play(string file) {
    
    ui.output_message("Enter the character you want to play with\n");
    ui.output_message("Human (h)\n");
    ui.output_message("Elf (e)\n");
    ui.output_message("Dwarf (d)\n");
    ui.output_message("Orc (o)\n");
    CommandType c = ui.getNextInput();
    if(c == CommandType::h)
        hero = shared_ptr <PC> (new Human());
    else if(c == CommandType::e)
        hero = shared_ptr <PC> (new Elf());
    else if(c == CommandType::d)
        hero = shared_ptr <PC> (new Dwarf()); 
    else
        hero = shared_ptr <PC> (new Orc());
    
    vector <vector <CellType>> layout;
    map <pair <int, int>, shared_ptr<Sprite>> sprite_coords;

    ui.read_floor(file, layout, sprite_coords);
 
    g.setUpMap(layout);
    
    g.initialize(hero);
    
    g.populate(sprite_coords);

    string action = "Player character has spawned";
    bool restart = false;
    while(true) {

	ui.output(g.getGrid());
        
        ui.output_message("Race: " + ui.convert(hero->getType()) + " Gold: ");
        ui.output_number(hero->score());

        for(int i = 0; i < 50; i++)
            ui.output_message(" ");
        
        ui.output_message("Floor ");
        ui.output_number(g.getFloorCount());
        ui.newline();

        ui.output_message("HP: ");
        ui.output_number(hero->getHP());
        ui.newline();
        
        ui.output_message("Atk: ");
        ui.output_number(hero->getAtk());
        ui.newline();
        
            
        ui.output_message("Def: ");
        ui.output_number(hero->getDef());
        ui.newline();
        
        ui.output_message("Action: " + action + "\n\n");

        ui.display_commands();

        pair <CommandType, CommandType> command_pair;
        CommandType input1 = CommandType::no_value;
        CommandType input2 = ui.getNextInput();
        if(input2 == CommandType::a || input2 == CommandType::d) {
            input1 = ui.getNextInput();
        }       
        else if(input2 == CommandType::r) {
            // delete hero;
            ui.output_message("Restarting the game\n");
            restart = true;
            break;
        }
        else if(input2 == CommandType::q) {
            // delete hero;
            ui.output_message("Thanks for playing the game\n");
            break;
        }
        else if(g.getFloorCount() > 5) {
            // delete hero;
            ui.output_message("You Won! Congratulations!\n");
            break;
        }
        else if(hero->getHP() == 0) {
            // delete hero;
            ui.output_message("You Lost!\n");
            break;
        }

       // pair <CommandType CommandType> command_pair = make_pair(input1, input2);
       // g.nextTurn(command_pair);
        g.nextTurn(make_pair(input1, input2));
    }
    if(restart)
        play(file);

}



