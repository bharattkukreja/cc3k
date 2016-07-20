#include <vector>
#include <unique_ptr>
#include "gamemap.h"
#include "cell.h"
#include "commands.h"

using namespace std;

// Implementation of GameMap class, see gamemap.h for documentation

// static constants

const unsigned int GameMap::width = 79;
const unsigned int GameMap::height = 30;
const unsigned int GameMap::chamber_num = 5;

// Methods

GameMap::GameMap() : floor_count{0} {}

void GameMap::setUpMap(vector<vector<CellType>> &c_grid){
	for(int r=0; r<width; r++){
		grid.emplace_back(vector<Cell>());
		for(int c=0; c<height; c++){
			grid.emplace_back(Cell(c_grid[r][c]));
			
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
	for(int r=0; r<width; r++){
                grid.emplace_back(vector<Cell>());
                for(int c=0; c<height; c++){
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

void GameMap::populate(){
	// place hero
	for(int r=1; r<height-1; r++){
		for(int c=1; c<width-1; c++){
			if(grid[r][c].getType() == CellType::Floor){
				grid[r][c].sprite = hero;
				r = height;
				c = width;
			}
		}
	}
	// spawn stairs
	for(int r=height-2; r>0; r--){
		for(int c=width-2; c>0; c--){
			if(grid[r][c].getType() == CellType::Floor){
                                grid[r][c].sprite = &(Stairs());
                                r = height;     
                                c = width;
                        }
		}
	}
	
	// spawn potions

	// spawn gold

	// spawn enemies

}

void GameMap::initialize(unique_ptr<PC> &hero){
	this.hero = hero;
	floor_count{1};
	populate();
}

void GameMap::clear(){
	for(auto row: grid){
		for(auto cell: grid){
			cell.sprite = nullptr;
		}
	}
}

// Based on command, change target direction (r, c)
void decideDirection(pair<CommandType, CommandType> &c_type, unsigned int & r, unsigned int & c){
	if(c_type.second == CommandType::nn && r>0){
                r--;
        } else if(c_type.second == CommandType::ne && r>0
                                                   && c<width){
                r--;
                c++;
        } else if(c_type.second == CommandType::nw && r>0
                                                   && c>0){
                r--;
                c--;
        } else if(c_type.second == CommandType::ss && r<height){
                r++;
        } else if(c_type.second == CommandType::se && r<height
                                                   && c<width){
                r++;
                c++;
        } else if(c_type.second == CommandType::sw && r<height
                                                   && c>0){
                r++;
                c--;
        } else if(c_type.second == CommandType::ee && c<width){
                c++;
        } else if(c_type.second == CommandType::ww && c>0){
                c--;
        }
}

void GameMap::nextTurn(pair<CommandType, CommandType> &c_type){
	// hero action
	unique_ptr<Cell> target;
	unsigned int r = player_location.first;
	unsigned int c = player_location.second;

	decideDirection(c_type, r, c);
	target = grid[r][c];

	if((r==player_location.first && c==player_location.second) 
		|| target.getType() == CellType::Wall_vertical || target.getType() == CellType::Wall_horizontal){
		target = nullptr;
		// invalid location to move to
	}

	if(c_type.first == CommandType::u){
		// use potion at c_type.second
		if(target!=nullptr && !target->isEmpty() && target->sprite->isItem()){
			dynamic_pointer_cast<Item>(target->sprite)->use(hero);
			delete target->sprite;
			target->sprite = nullptr;
		}

	} else if(c_type.first == CommandType::a){
		// attack enemy at c_type.second
		if(target!=nullptr && !target->isEmpty() && target->sprite->isEnemy()){
			unique_ptr<Enemy> e = dynamic_pointer_cast<Enemy>(target->sprite);
			hero->hit(e);
			
			// remove npc if its HP is less than 0
			if(e->getHP()<=0){
				delete target->sprite;
				target->sprite = nullptr;
			}
		}

	} else {
		// try to move to this location
		if(target != nullptr && (target->getType() == SpriteType::Stairs)) {
			floor_count++;
			clear();
			populate();
			return;
		} else if(target!=nullptr && (target->isEmpty() || target->sprite->Type() == SpriteType::Gold)){
			// use gold
			if(target->sprite->getType() == SpriteType::Gold){
				dynamic_pointer_cast<Potion>(target->sprite)->use(hero);
                        	delete target->sprite;
                        	target->sprite = nullptr;
			}
			
			// move hero
			target->sprite = hero;
			grid[player_location.first][player_location.second] = nullptr;
			player_location.first = r;
			player_location.second = c;
		}
	}

	ai.nextTurn();
}

unsigned int GameMap::getFloorCount() const {
	return floor_count;
}

vector<vector<Cell>> GameMap::getGrid() const {
	return grid;
}

bool GameMap::isWon() const {
	return won;
}

GameMap::~GameMap(){
	clear();
}
