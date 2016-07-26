#include "gamehandler.h"
#include "ui.h"
#include "gamemap.h"
#include "pc.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "orc.h"
#include <utility>

using namespace std;

GameHandler::GameHandler(GameMap &g, UI &ui) : g{g}, ui{ui} {}

void GameHandler::play(string file) {
    
    ui.output_message("Enter the character you want to play with\n");
    ui.output_message("Human (h)\n");
    ui.output_message("Elf (e)\n");
    ui.output_message("Dwarf (d)\n");
    ui.output_message("Orc (o)\n");
    CommandType c = ui.getNextInput();
    
    bool default_map;   // is true if the map is the defualt one(empty)
    if(c == CommandType::e)
        hero = shared_ptr <PC> (new Elf());
    else if(c == CommandType::d)
        hero = shared_ptr <PC> (new Dwarf()); 
    else if(c == CommandType::o)
        hero = shared_ptr <PC> (new Orc());
    else 
        hero = shared_ptr <PC> (new Human());
    
    vector <vector <CellType>> layout;
    map <pair <int, int>, shared_ptr<Sprite>> sprite_coords;
    
    ui.read_file(file);
    default_map = ui.read_floor(layout, sprite_coords);
    
    // Sets up the grid
    g.setUpMap(layout);
    
    g.initialize(hero);
    
    if(default_map)
        g.populate();
    else
        g.populate(sprite_coords);

    string action = "Player character has spawned";
    bool restart = false;
    while(true) {
        
	ui.output(g.getGrid());
        unsigned int floor_count = g.getFloorCount();

        ui.output_message("Race: " + ui.convert(hero->getType()) + " Gold: ");
        ui.output_number(hero->getGold());

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
        
        if(hero->getHP() <= 0) {
            // delete hero;
            ui.output_message("Player was killed. You Lost!\n");
            break;
        }


        ui.display_commands();

        pair <CommandType, CommandType> command_pair;
        
        // input1 : u/a, input2 : direction 
        CommandType input1 = CommandType::no_value;
        CommandType input2 = ui.getNextInput();
        
        if(input2 == CommandType::a || input2 == CommandType::u) {
            input1 = input2;
            input2 = ui.getNextInput();
        }       
        else if(input2 == CommandType::r) {
            ui.output_message("Restarting the game\n");
            restart = true;
            break;
        }
        else if(input2 == CommandType::q) {
            ui.output_message("Thanks for playing the game\n");
            break;
        }
 
        string direction;
        if(input1 == CommandType::no_value) {
            direction = ui.convert_direction(input2);
        }
    
        action = g.nextTurn(make_pair(input1, input2));
        ui.put_direction(action, direction);

        if(g.getFloorCount() > 5) {
            ui.output_message("You Won! Congratulations!\n");
            break;
        }
        
        if(g.getFloorCount() != floor_count) {
            sprite_coords.clear();
            if(!default_map) {
                layout.clear();
                default_map = ui.read_floor(layout, sprite_coords);
            }
                       
            g.setUpMap(layout);
            if(default_map)
                g.populate();
            else
                g.populate(sprite_coords);
        }

    }
    
    if(restart) {
        play(file);
    }
    else {

        ui.output_message("Do you want to play again? (y/n)\n");
        if(ui.getNextInput() == CommandType::y)
            play(file);
    }
    
}



