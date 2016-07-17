#include "gamehandler.h"

using namespace std;

void GameHandler::play() {
    
    ui.output_message("Enter the character you want to play with");
    Commandtype c = ui.getNextInput();
    if(c == CommandType::h)
        hero = new Human();
    else if(c == CommandType::e)
        hero = new Elf();
    else if(c == CommandType::d)
        hero = new Dwarf();
    else
        hero = new Orc();
    
    g.initialize(hero);
    
    while(true) {
        pair <CommandType CommandType> command_pair;
        CommandType input1 = Commandtype::no_value;
        Commandtype input2 = ui.getNextInput();
        if(input2 == Commandtype::a || input2 == Commandtype::d) {
            input1 = ui.getNextInput();
        }       
        else if(input2 == Commandtype::r) {
            delete hero;
            play();
        }
        else if(input2 == Commandtype::q) {
            delete hero;
            ui.output_message("Thanks for playing the game");
            break;
        }
        command_pair = make_pair(input1, input2);
        g.nextTurn(command_pair);
    }

}



