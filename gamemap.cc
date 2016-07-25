#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
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

GameMap::GameMap() : floor_count{1} {
//	grid = vector<vector<Cell>>();
}

void GameMap::setUpMap(vector<vector<CellType>> &c_grid){
    if(grid.size()>0){
 	for(auto row: grid){
	   row.clear();
	}
    }
    grid.clear();

    for(unsigned int r=0; r<c_grid.size(); r++){
	grid.emplace_back(vector<Cell>());
	for(unsigned int c=0; c<c_grid[r].size(); c++){
	    grid[r].emplace_back(Cell(c_grid[r][c], r, c));
			
            if(grid[r][c].getType()==CellType::Wall_horizontal
                || grid[r][c].getType()==CellType::Wall_vertical
                || grid[r][c].getType()==CellType::Space){
                continue;
            }

        }
    }

    for(unsigned int r=1; r<grid.size()-1; r++){
        for(unsigned int c=1; c<grid.size()-1; c++){
            if(grid[r][c].getType()!=CellType::Floor){
                continue;
            }

            if(r>0 && grid[r-1][c].getType()!=CellType::Wall_horizontal
                   && grid[r-1][c].getType()!=CellType::Wall_vertical
                   && grid[r-1][c].getType()!=CellType::Space){
                grid[r][c].attach(grid[r-1][c]);
            }

            if(r>0 && c>0 && grid[r-1][c-1].getType()!=CellType::Wall_horizontal
                   && grid[r-1][c-1].getType()!=CellType::Wall_vertical
                   && grid[r-1][c-1].getType()!=CellType::Space){
                grid[r][c].attach(grid[r-1][c-1]);
            }

            if(c>0 && grid[r][c-1].getType()!=CellType::Wall_horizontal
                   && grid[r][c-1].getType()!=CellType::Wall_vertical
                   && grid[r][c-1].getType()!=CellType::Space){
                grid[r][c].attach(grid[r][c-1]);
            }
                
            if(r>0 && c<grid[r].size() && grid[r-1][c+1].getType()!=CellType::Wall_horizontal
                   && grid[r-1][c+1].getType()!=CellType::Wall_vertical
                   && grid[r-1][c+1].getType()!=CellType::Space){
                 grid[r][c].attach(grid[r-1][c+1]);
            }

            if(r<grid.size() && grid[r+1][c].getType()!=CellType::Wall_horizontal
                   && grid[r+1][c].getType()!=CellType::Wall_vertical
                   && grid[r+1][c].getType()!=CellType::Space){
                grid[r][c].attach(grid[r+1][c]);
            }

            if(r<grid.size() && c>0 && grid[r+1][c-1].getType()!=CellType::Wall_horizontal
                   && grid[r+1][c-1].getType()!=CellType::Wall_vertical
                   && grid[r+1][c-1].getType()!=CellType::Space){
                grid[r][c].attach(grid[r+1][c-1]);
            }

            if(c<grid[r].size() && grid[r][c+1].getType()!=CellType::Wall_horizontal
                   && grid[r][c+1].getType()!=CellType::Wall_vertical
                   && grid[r][c+1].getType()!=CellType::Space){
                grid[r][c].attach(grid[r][c+1]);
            }
                
            if(r<grid.size() && c<grid[r].size() && grid[r+1][c+1].getType()!=CellType::Wall_horizontal
                   && grid[r+1][c+1].getType()!=CellType::Wall_vertical
                   && grid[r+1][c+1].getType()!=CellType::Space){
                 grid[r][c].attach(grid[r+1][c+1]);
            }

        }
    }

 //	ai = AI{grid};
}

void GameMap::setUpMap(){
}

void GameMap::populate(map<pair<int, int>, shared_ptr<Sprite>> &sprite_locations){
        for(auto it = sprite_locations.begin(); it!=sprite_locations.end(); ++it){
                if(sprite_locations[it->first]->getType() == SpriteType::Human){
                        sprite_locations[it->first].reset();
                        grid[(it->first).first][(it->first).second].sprite = hero;
			player_location.first = it->first.first;
			player_location.second = it->first.second;
                } else {
                        grid[(it->first).first][(it->first).second].sprite = sprite_locations[it->first];
			if(sprite_locations[it->first]->isNPC())
				enemy_locations.emplace_back(pair<int , int>(it->first.first, it->first.second));
                }
        }
}

void generate_batch(Cell &c, vector<Cell*> &chamber) {
    if(chamber.size() == 0 || find(chamber.begin(), chamber.end(), &c) == chamber.end()){
	chamber.emplace_back(&c);
	auto observers = c.getObservers();
	for(auto observer: observers){
	    generate_batch(*observer, chamber);
	}
    }
}

void GameMap::populate(){

    // spawning PC
    auto chambers = vector<vector<Cell*>>(); 
    for(unsigned int r=0; r<grid.size(); r++) {
        for(unsigned int c=0; c<grid[r].size(); c++){
            bool isThere = false;
            if(grid[r][c].getType() == CellType::Floor) {
                // checking if 
                for(unsigned int z = 0; z < chambers.size(); z++) {
                    if(find(chambers[z].begin(), chambers[z].end(), &grid[r][c]) != chambers[z].end()) {
                        isThere = true;
                        break;
                    }
                }

            	if(!isThere) {
                	vector <Cell*> temp;
                	generate_batch(grid[r][c], temp);
			//cout << temp.size() << ", ";
	          	chambers.emplace_back(temp);
			r = 0;
			c = 0;
            	}
	    }
        }
    }
   
    srand(time(NULL));
    int random_chamber = rand() % chambers.size();
    int random_cell = rand() % chambers[random_chamber].size();
    
    //cout << "abx" << random_chamber << " " << chambers[random_chamber].size() << endl;

    player_location.first = chambers[random_chamber][random_cell]->getRow();
    player_location.second = chambers[random_chamber][random_cell]->getCol();
    grid[player_location.first][player_location.second].sprite = hero;
/*
    int count = 1;
    for (int i = 1; i < GameMap::height - 1; i++) {
        for (int j = 1; j < GameMap::width - 1; j++) {
            if(grid[i][j] == CellType::Wall_vertical) {
                         
            }
        }
    }
*/
/*
    // place hero
    bool lbreak = false;
    for(unsigned int r=1; r<grid.size()-1; r++){
	for(unsigned int c=1; c<grid[r].size()-1; c++){
	    if(grid[r][c].getType() == CellType::Floor){
	        grid[r][c].sprite = shared_ptr<Sprite>(hero);
		player_location.first = r;
		player_location.second = c;
		lbreak  = true;
		break;
	    }
    	}
	if(lbreak) break;
    }

    // spawn stairs
    lbreak = false;
    for(unsigned int r=grid.size()-1; r>0; r--){
	for(unsigned int c=grid[r].size()-1; c>0; c--){
	    if(grid[r][c].getType() == CellType::Floor){
                grid[r][c].sprite = shared_ptr<Sprite>(new Stairs());
                lbreak  = true;
                break;
	    }
	}
	if(lbreak) break;
    }
*/	
    // spawn potions

    // spawn gold

    // spawn enemies

}

void GameMap::initialize(shared_ptr<PC> hero){
    this->hero.reset();
    this->hero = hero;
    floor_count = 1;
    //populate();
}

void GameMap::clear(){
    for(auto row: grid){
        for(auto cell: row){
            cell.sprite = nullptr;
        }
    }
}

// Based on command, change target direction (r, c)
void GameMap::decideDirection(pair<CommandType, CommandType> &c_type, unsigned int & r, unsigned int & c){
    if(c_type.second == CommandType::no && r>0){
        r--;

    } else if(c_type.second == CommandType::ne && r>0
                                               && c<grid[0].size()){
        r--;
        c++;
    
    } else if(c_type.second == CommandType::nw && r>0
                                               && c>0){
        r--;
        c--;

    } else if(c_type.second == CommandType::so && r<grid.size()){
        r++;
    
    } else if(c_type.second == CommandType::se && r<grid.size()
                                               && c<grid[0].size()){
        r++;
        c++;

    } else if(c_type.second == CommandType::sw && r<grid.size()
                                               && c>0){
        r++;
        c--;

    } else if(c_type.second == CommandType::ea && c<grid[0].size()){
        c++;
    
    } else if(c_type.second == CommandType::we && c>0){
        c--;
    
    }
}

// Converts a SpriteType to a string
string stringifyType(SpriteType x){
	string potType;
	if(x == SpriteType::AtkPot){
		potType = "AtkPot";
	} else if(x == SpriteType::DefPot){
		potType = "DefPot";
	} else if(x == SpriteType::HPPot){
		potType = "HPPot";
	} else if(x == SpriteType::Gold){
		potType = "Gold";
        } else if(x == SpriteType::Goblin){
	        potType = "Goblin";
        } else if(x == SpriteType::Merchant){
                potType = "Merchant";
        } else if(x == SpriteType::Dragon){
                potType = "Dragon";
        } else if(x == SpriteType::Vampire){
                potType = "Vampire";
        } else if(x == SpriteType::Werewolf){
                potType = "Werewolf";
        } else if(x == SpriteType::Troll){
                potType = "Troll";
        } else {
                potType = "Phoenix";
        }

	return potType;
}

string GameMap::nextTurn(pair<CommandType, CommandType> c_type){
	// hero action
	// make shared? (idk how to make it work
	Cell *target;
	unsigned int r = player_location.first;
	unsigned int c = player_location.second;

	string action = "";

	decideDirection(c_type, r, c);
	target = &grid[r][c];

	if((r==player_location.first && c==player_location.second) 
		|| target->getType() == CellType::Wall_vertical 
		|| target->getType() == CellType::Wall_horizontal
		|| target->getType() == CellType::Space){
		target = nullptr;
		// invalid location to move to
	}

	if(c_type.first == CommandType::u){

		// use potion at c_type.second
		if(target!=nullptr && !target->isEmpty() && target->sprite->isItem()){
			(dynamic_pointer_cast<Item>(target->sprite))->use(*hero);

			string potType = stringifyType(target->sprite->getType());
			action = "Player used " + potType;
			target->sprite = nullptr;
		}

	} else if(c_type.first == CommandType::a){
		// attack enemy at c_type.second
	
		if(target!=nullptr && !target->isEmpty() && target->sprite->isNPC()){
			NPC &e = *dynamic_pointer_cast<NPC>(target->sprite);
			unsigned int hp = e.getHP();
			hero->hit(e);

			string potType = stringifyType(target->sprite->getType());

			action = "Player hit " + potType + " and dealt " + to_string(hp - e.getHP()) + " dmg";

			// remove npc if its HP is less than 0
			if(e.getHP()<=0 || e.getHP()>hp){ //unsigned int in enemy, so hp actually increases instead of going below 0, needs to be fixed
				hero->changeGold(e.getGoldDropped());
				target->sprite = nullptr;
				action = "Player killed " + potType;
			}
		}

	} else {
		// try to move to this location
		if(target != nullptr && !target->isEmpty() && (target->sprite->getType() == SpriteType::Stairs)) {
			grid[player_location.first][player_location.second].sprite = nullptr;
			floor_count++;
			clear();
			populate();
			return "Player reached floor " + to_string(floor_count);
		} else if(target!=nullptr && (target->isEmpty() || target->sprite->getType() == SpriteType::Gold)){
			// use gold
			if(!target->isEmpty() && target->sprite->getType() == SpriteType::Gold){
				dynamic_pointer_cast<Item>(target->sprite)->use(*hero);
                        	target->sprite.reset();
                        	target->sprite = nullptr;
				action = "Player used Gold";
			} else {
			
				// move hero
				target->sprite = hero;
				unsigned int hp = hero->getHP();
				grid[player_location.first][player_location.second].sprite = nullptr;
				player_location.first = r;
				player_location.second = c;
				target->notifyAll();

				if(hp != hero->getHP()) { // player was hit
					for(auto observer: target->getObservers()){ // find out which npc
						if(observer->hasAttacked() && observer->sprite!=nullptr){
							string enType = stringifyType(observer->sprite->getType());
							action = "Player was attacked by " + enType + ", losing " + to_string(hp - hero->getHP()) + " HP";
							break;
						}
					}
				} else {
					action =  "Player moved";
				}
			}
		}
	}

	ai.move(enemy_locations, grid);
	return action;
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
