#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include "gamemap.h"
#include "cell.h"
#include "commands.h"
#include "sprite.h"
#include "pc.h"
#include "npc.h"
#include "item.h"
#include "potion.h"
#include "stairs.h"

using namespace std;

// Implementation of GameMap class, see gamemap.h for documentation

// static constants

const unsigned int GameMap::width = 79;
const unsigned int GameMap::height = 30;

// Methods

GameMap::GameMap() : ai{AI(grid)}, floor_count{1} {
	grid = vector<vector<Cell>>();
}

void GameMap::setUpMap(vector<vector<CellType>> &c_grid){
    for(unsigned int r=0; r<width; r++){
	grid.emplace_back(vector<Cell>());
	for(unsigned int c=0; c<height; c++){
	    grid[r].emplace_back(Cell(c_grid[r][c]));
			
            if(grid[r][c].getType()==CellType::Wall_horizontal
                && grid[r][c].getType()==CellType::Wall_vertical
                && grid[r][c].getType()==CellType::Space){
                continue;
            }

            if(r>0 && grid[r-1][c].getType()!=CellType::Wall_horizontal
                   && grid[r-1][c].getType()!=CellType::Wall_vertical
                   && grid[r-1][c].getType()!=CellType::Space){
                grid[r-1][c].attach(grid[r][c]);
                grid[r][c].attach(grid[r-1][c]);
            }

            if(c>0 && grid[r][c-1].getType()!=CellType::Wall_horizontal
                   && grid[r][c-1].getType()!=CellType::Wall_vertical
                   && grid[r][c-1].getType()!=CellType::Space){
                grid[r][c-1].attach(grid[r][c]);
                grid[r][c].attach(grid[r][c-1]);
            }
	}
    }
}

void GameMap::setUpMap(){
    // temporary simplification of maps
    for(unsigned int r=0; r<GameMap::width; r++){
        grid.emplace_back(vector<Cell>());
        for(unsigned int c=0; c<GameMap::height; c++){
            if(r==0 || r==width-1){
                grid[r].emplace_back(Cell(CellType::Wall_horizontal));
            } else if(c==0 || r==height-1) {
                grid[r].emplace_back(Cell(CellType::Wall_vertical));
            } else {
                grid[r].emplace_back(Cell(CellType::Floor));
            }

            if(grid[r][c].getType()==CellType::Wall_horizontal
                && grid[r][c].getType()==CellType::Wall_vertical
                && grid[r][c].getType()==CellType::Space){
                continue;
            }

            if(r>0 && grid[r-1][c].getType()!=CellType::Wall_horizontal
                   && grid[r-1][c].getType()!=CellType::Wall_vertical
                   && grid[r-1][c].getType()!=CellType::Space){
                
                grid[r-1][c].attach(grid[r][c]);
                grid[r][c].attach(grid[r-1][c]);
            
            }

            if(c>0 && grid[r][c-1].getType()!=CellType::Wall_horizontal
                   && grid[r][c-1].getType()!=CellType::Wall_vertical
                   && grid[r][c-1].getType()!=CellType::Space){
                grid[r][c-1].attach(grid[r][c]);
                grid[r][c].attach(grid[r][c-1]);
            }
        }
    }
}

/*void generate_batch(Cell &c, vector<shared_ptr<Cell>> &chamber) {
	if(chamber.size() == 0 || find(chamber.begin(), chamber.end(), c) == chamber.end()){
		chamber.add(shared_ptr<Cell>(*c));
		auto observers = chamber.getObservers();
		for(auto observer: observers){
			generate_batch(*observer, chamber);
		}
	}
}*/

void GameMap::populate(){

/*    // spawning PC
    auto chambers = vector<vector<shared_ptr<Cell>>> 
    int num_chambers = 5;
    for(int i=0; i<num_chambers; i++){
  	// get start index, Cell start
	Cell &start;
	for(auto row: grid){
	    for(auto cell: row){
		bool next_start =  
	    }
	}

	auto chamber = vector<vector<shared_ptr<Cell>>>(); 
	generate_batch();
	chambers.emplace_back(start, chamber);
    }

    int count = 1;
    for (int i = 1; i < GameMap::height - 1; i++) {
        for (int j = 1; j < GameMap::width - 1; j++) {
            if(grid[i][j] == CellType::Wall_vertical) {
                         
            }
        }
    }
*/
    // place hero
    for(unsigned int r=1; r<GameMap::height-1; r++){
	for(unsigned int c=1; c<GameMap::width-1; c++){
	    if(grid[r][c].getType() == CellType::Floor){
	        grid[r][c].sprite = shared_ptr<Sprite>(hero);
		r = height;
		c = width;
	    }
    	}
    }

    // spawn stairs
    for(unsigned int r=GameMap::height-2; r>0; r--){
	for(unsigned int c=GameMap::width-2; c>0; c--){
	    if(grid[r][c].getType() == CellType::Floor){
                grid[r][c].sprite = shared_ptr<Sprite>(new Stairs());
                r = height;     
                c = width;
            }
	}
    }
	
    // spawn potions

    // spawn gold

    // spawn enemies

}

void GameMap::initialize(shared_ptr<PC> hero){
    this->hero.reset();
    this->hero = hero;
    floor_count = 1;
    populate();
}

void GameMap::clear(){
    for(auto row: grid){
        for(auto cell: row){
            if(!cell.sprite->isPC()){
                cell.sprite.reset();
            }
            cell.sprite = nullptr;
        }
    }
}

// Based on command, change target direction (r, c)
void GameMap::decideDirection(pair<CommandType, CommandType> &c_type, unsigned int & r, unsigned int & c){
    if(c_type.second == CommandType::no && r>0){
        r--;
    } else if(c_type.second == CommandType::ne && r>0
                                               && c<GameMap::width){
        r--;
        c++;
    } else if(c_type.second == CommandType::nw && r>0
                                               && c>0){
        r--;
        c--;
    } else if(c_type.second == CommandType::so && r<GameMap::height){
        r++;
    } else if(c_type.second == CommandType::se && r<GameMap::height
                                               && c<GameMap::width){
        r++;
        c++;
    } else if(c_type.second == CommandType::sw && r<GameMap::height
                                               && c>0){
        r++;
        c--;
    } else if(c_type.second == CommandType::ea && c<GameMap::width){
        c++;
    } else if(c_type.second == CommandType::we && c>0){
        c--;
    }
}

void GameMap::nextTurn(pair<CommandType, CommandType> c_type){
	// hero action
	unique_ptr<Cell> target;
	unsigned int r = player_location.first;
	unsigned int c = player_location.second;

	decideDirection(c_type, r, c);
	target = unique_ptr<Cell>(&grid[r][c]);

	if((r==player_location.first && c==player_location.second) 
		|| target->getType() == CellType::Wall_vertical || target->getType() == CellType::Wall_horizontal){
		target = nullptr;
		// invalid location to move to
	}

	if(c_type.first == CommandType::u){
		// use potion at c_type.second
		if(target!=nullptr && !target->isEmpty() && target->sprite->isItem()){
			(dynamic_pointer_cast<Item>(target->sprite))->use(*hero);
			target->sprite.reset();
			target->sprite = nullptr;
		}

	} else if(c_type.first == CommandType::a){
		// attack enemy at c_type.second
		if(target!=nullptr && !target->isEmpty() && target->sprite->isNPC()){
			NPC &e = *dynamic_pointer_cast<NPC>(target->sprite);
			hero->hit(e);
			
			// remove npc if its HP is less than 0
			if(e.getHP()<=0){
				target->sprite.reset();
				target->sprite = nullptr;
			}
		}

	} else {
		// try to move to this location
		if(target != nullptr && (target->sprite->getType() == SpriteType::Stairs)) {
			floor_count++;
			clear();
			populate();
			return;
		} else if(target!=nullptr && (target->isEmpty() || target->sprite->getType() == SpriteType::Gold)){
			// use gold
			if(target->sprite->getType() == SpriteType::Gold){
				dynamic_pointer_cast<Potion>(target->sprite)->use(*hero);
                        	target->sprite.reset();
                        	target->sprite = nullptr;
			}
			
			// move hero
			target->sprite = hero;
			grid[player_location.first][player_location.second].sprite = nullptr;
			player_location.first = r;
			player_location.second = c;
		}
	}

	ai.move();
}

unsigned int GameMap::getFloorCount() const {
    return floor_count;
}

vector<vector<Cell>> &GameMap::getGrid() {
    return grid;
}

GameMap::~GameMap(){
    clear();
}
