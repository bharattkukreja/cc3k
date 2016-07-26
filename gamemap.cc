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

            if(r>0 && grid[r-1][c].getType()==CellType::Floor){
                grid[r][c].attach(grid[r-1][c]);
            }

            if(r>0 && c>0 && grid[r-1][c-1].getType()==CellType::Floor){
                grid[r][c].attach(grid[r-1][c-1]);
            }

            if(c>0 && grid[r][c-1].getType()==CellType::Floor){
                grid[r][c].attach(grid[r][c-1]);
            }
             
	    if(r<grid.size() && c>0 && grid[r+1][c-1].getType()==CellType::Floor){
                grid[r][c].attach(grid[r+1][c-1]);
            }
   
            if(r<grid.size() && grid[r+1][c].getType()==CellType::Floor){
                grid[r][c].attach(grid[r+1][c]);
            }

            if(r<grid.size() && c<grid[r].size() && grid[r+1][c+1].getType()==CellType::Floor){
                 grid[r][c].attach(grid[r+1][c+1]);
            }

            if(c<grid[r].size() && grid[r][c+1].getType()==CellType::Floor){
                grid[r][c].attach(grid[r][c+1]);
            }  

            if(r>0 && c<grid[r].size() && grid[r-1][c+1].getType()==CellType::Floor){
                 grid[r][c].attach(grid[r-1][c+1]);
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

			// Dragons watch their hoards
			if(sprite_locations[it->first]->getType() == SpriteType::Dragon){
				grid[(it->first).first][(it->first).second].clear();
				for(auto observer: grid[(it->first).first][(it->first).second].getObservers()){
					grid[(it->first).first][(it->first).second].attach(*observer);
				}
			}
                }
        }
}

void GameMap::generate_batch(Cell &c, vector<Cell*> &chamber) {
    bool found = false;
    for(auto cell: chamber){
	if(cell->getRow() == c.getRow() && cell->getCol() == c.getCol()){
		found = true;
		break;
	}
    }

    if(!found){
	chamber.emplace_back(&c);
        for(unsigned int r=0; r<=1; r++){
	    for(unsigned int c2=0; c2<=1; c2++){
		unsigned int rp = r+c.getRow();
		unsigned int cp = c2+c.getCol();
		if(rp>0 && rp<grid.size()&&cp>0&&cp<grid[0].size()&&grid[rp][cp].getType()==CellType::Floor){
			generate_batch(grid[rp][cp], chamber);
		}
	    }
        }
    }
}

void GameMap::populate(){
    
    int random_chamber;
    int random_pos;
    Cell* random_cell;    

    // spawning PC
    auto chambers = vector<vector<Cell*>>(); 
    for(unsigned int r=0; r<grid.size(); r++) {
        for(unsigned int c=0; c<grid[r].size(); c++){
            bool isThere = false;
            if(grid[r][c].getType() == CellType::Floor) {
                // checking if 
                for(unsigned int z = 0; z < chambers.size(); z++) {
		    bool found = false;
    		    for(auto cell: chambers[z]){
                    	if(cell->getRow() == grid[r][c].getRow() && cell->getCol() == grid[r][c].getCol()){
                	    found = true;
                	    break;
        	    	}
    		    }
			
		    if(found){
                        isThere = true;
                        break;
                    }
                }

            	if(!isThere) {
                	vector <Cell*> temp;
                	generate_batch(grid[r][c], temp);
	          	chambers.emplace_back(temp);
            	}
	    }
        }
    }
   
    srand(time(NULL));
    random_chamber = rand() % chambers.size();
    random_pos = rand() % chambers[random_chamber].size();
    
    player_location.first = chambers[random_chamber][random_pos]->getRow();
    player_location.second = chambers[random_chamber][random_pos]->getCol();
    grid[player_location.first][player_location.second].sprite = hero;

    // spawn stairs
    unsigned int rand_stairs = rand()%chambers.size();
    if(rand_stairs==random_chamber){
	if(rand_stairs<chambers.size()-1){
	    rand_stairs++;
	} else {
	    rand_stairs--;
	}
    }
    random_pos = rand() % chambers[rand_stairs].size();
    chambers[rand_stairs][random_pos]->sprite = shared_ptr<Stairs>(new Stairs());

    // spawn potions
    
    int total_potions = 3;
    int potion_count = 0;
            
    while(potion_count < 10) {
                    
        int random_potion = rand() % total_potions;
        int positivity = rand() % 2;

        while(true) {
            random_chamber = rand() % chambers.size();
            random_pos = rand() % chambers[random_chamber].size();
            random_cell = chambers[random_chamber][random_pos];
            if(random_cell->isEmpty())
                break;
        }

        if(random_potion == 0) {
            if(positivity == 0)
                random_cell->sprite = shared_ptr<HPPot>(new HPPot(false));
            else
                random_cell->sprite = shared_ptr<HPPot>(new HPPot(true));
        }
        
        else if(random_potion == 1) {
            if(positivity == 0)
                random_cell->sprite = shared_ptr<AtkPot>(new AtkPot(false));
            else
                random_cell->sprite = shared_ptr<AtkPot>(new AtkPot(true));
        }                                    
        
        else {
            if(positivity == 0)
                random_cell->sprite = shared_ptr<DefPot>(new DefPot(false));
            else 
                random_cell->sprite = shared_ptr<DefPot>(new DefPot(true));
        }

        potion_count++;
    }


    // spawn gold
    
    int gold_count = 0;

    while(gold_count < 10) {
        int random_gold = rand() % 8;

        while(true) {
            random_chamber = rand() % chambers.size();
            random_pos = rand() % chambers[random_chamber].size();
            random_cell = chambers[random_chamber][random_pos];
            if(random_cell->isEmpty())
                break;
        }

                               
        // Small horde has probability 1/4 = 2/8
        if(random_gold <= 1)
            random_cell->sprite = shared_ptr<Gold>(new Gold(1));
                               
        // Normal horde has probability 5/8
        else if(random_gold > 1 && random_gold <= 6)
            random_cell->sprite = shared_ptr<Gold>(new Gold(2));
                                                                                                
        // Dragon horde has probability 1/8
        else {
            random_cell->sprite = shared_ptr<Gold>(new Gold(6));
            while(true) {
                int x = 1 - (rand() % 3);
                int y = 1 - (rand() % 3);
                Cell* dragon_pos = &grid[random_cell->getRow() + x][random_cell->getCol() + y];
                if(dragon_pos->isEmpty()) {
                    dragon_pos->sprite = shared_ptr<Dragon>(new Dragon());
                    enemy_locations.emplace_back(make_pair(dragon_pos->getRow(), dragon_pos->getCol()));
                    break;
                }                    
            }
        }
                               
        gold_count++;
    }                       


    // spawn enemies

    int enemy_count = 0;
    
    while(enemy_count < 10) {
        int random_enemy = rand() % 18;

        while(true) {
            random_chamber = rand() % chambers.size();
            random_pos = rand() % chambers[random_chamber].size();
            random_cell = chambers[random_chamber][random_pos];
            if(random_cell->isEmpty())
                break;
        }

        // Werewolf has probability 2/9 = 4/18
        if(random_enemy <= 3)
            random_cell->sprite = shared_ptr<Werewolf>(new Werewolf());

        // Vampire has probability 3/18
        else if(random_enemy > 3 && random_enemy <= 6)
            random_cell->sprite = shared_ptr<Vampire>(new Vampire());

        // Goblin has probability 5/18
        else if(random_enemy > 6 && random_enemy <= 11)
            random_cell->sprite = shared_ptr<Goblin>(new Goblin());

        // Troll has probability 1/9 = 2/18
        else if(random_enemy > 11 && random_enemy <= 13)
            random_cell->sprite = shared_ptr<Troll>(new Troll());

        // Phoenix has probability 1/9 = 2/18
        else if(random_enemy > 13 && random_enemy <= 15)
            random_cell->sprite = shared_ptr<Phoenix>(new Phoenix());

        // Merchant has probability 1/9 = 2/18
        else
            random_cell->sprite = shared_ptr<Merchant>(new Merchant());

        enemy_locations.emplace_back(make_pair(random_cell->getRow(), random_cell->getCol()));

        enemy_count++;
    }


/*    // spawn stairs
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
		potType = "Atk Potion";
	} else if(x == SpriteType::DefPot){
		potType = "Def Potion";
	} else if(x == SpriteType::HPPot){
		potType = "HP Potion";
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

	int php = hero->getHP();
	int patk = hero->getAtk();
	int pdef = hero->getDef();

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

			if(target->sprite->getType() == SpriteType::AtkPot){
				action += ", Atk changed by " + to_string(hero->getAtk() - patk);
			} else if(target->sprite->getType() == SpriteType::DefPot){
				action += ", Def changed by " + to_string(hero->getDef() - pdef);
			} else if(target->sprite->getType() == SpriteType::HPPot){
				action += ", HP changed by " + to_string(hero->getHP() - php);
			}

			target->sprite = nullptr;
		}

	} else if(c_type.first == CommandType::a){
		// attack enemy at c_type.second
	
		if(target!=nullptr && !target->isEmpty() && target->sprite->isNPC()){
			NPC &e = *dynamic_pointer_cast<NPC>(target->sprite);
			unsigned int hp = e.getHP();
			hero->hit(e);

			string potType = stringifyType(target->sprite->getType());

			action = "Player hit " + potType + " (" + to_string(e.getHP()) + ") and dealt " + to_string(hp - e.getHP()) + " dmg";

			// remove npc if its HP is less than 0
			if(e.getHP()<=0){
				hero->changeGold(e.getGoldDropped());
				target->sprite = nullptr;
				for(auto en: enemy_locations){
					if(en.first == target->getRow() && en.second == target->getCol()){
						en.first = 0;
						en.second = 0;
					}
				}
				action = "Player killed " + potType;
			}
		}

	} else {
		// try to move to this location
		if(target != nullptr && !target->isEmpty() && (target->sprite->getType() == SpriteType::Stairs)) {
			grid[player_location.first][player_location.second].sprite = nullptr;
			enemy_locations.clear();
			floor_count++;
			clear();
			populate();
			return "Player moved and Player reached floor " + to_string(floor_count);
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
				grid[player_location.first][player_location.second].sprite = nullptr;
				player_location.first = r;
				player_location.second = c;
				target->notifyAll();

				action =  "Player moved";
			}
		}
	}

	if(php != hero->getHP()){
		for(auto observer: target->getObservers()){ // find out which npc
        	       if(observer->hasAttacked() && observer->sprite!=nullptr){
      	                     string enType = stringifyType(observer->sprite->getType());
                             action += " and Player was attacked by " + enType + ", losing " + to_string(php - hero->getHP()) + " HP";
                             break;
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
