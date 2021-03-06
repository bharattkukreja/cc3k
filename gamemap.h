#ifndef _GAME_MAP_HEADER_
#define _GAME_MAP_HEADER_

#include <vector>
#include <utility>
#include <map>
#include <string>
#include "commands.h"
#include "cell.h"
#include "ai.h"

class Sprite;
class PC;

// This is the GameMap class. This class stores and manages the Cell grid,
//   and Sprite interactions.
class GameMap {

	std::vector<std::vector<Cell>> grid; // This is the grid of Cells
	std::pair<unsigned int, unsigned int> player_location;
	std::vector<std::pair<unsigned int, unsigned int>> enemy_locations;
	std::vector<Sprite> sprites;
	std::shared_ptr<PC> hero;
	AI ai;
	unsigned int floor_count;

	// decides direction based on given command pair
	void decideDirection(std::pair<CommandType, CommandType> &c_type, unsigned int & r, unsigned int & c);

	// generates 'batches' of cells that denote individual chambers in the map
	void generate_batch(Cell &c, std::vector<Cell*> &chambers);

	// static constants
	static const unsigned int width;
	static const unsigned int height;
	
   public:

	GameMap();

	// Sets up the grid, i.e. constructs all Cells
        //    with the types given by the CellType grid 'map'
        void setUpMap(std::vector<std::vector<CellType>> &map);

	// Initializes the GameMap
	void initialize(std::shared_ptr<PC> hero);

	// Populates the grid, i.e. spawns all Sprites randomly 
        void populate();

	// populates the gamemap with a given map of locations of initialized sprite pointers
	void populate(std::map<std::pair<int, int>, std::shared_ptr<Sprite>> &sprite_locations);

	// Adjusts state to reflect effects of next turn of the game
	std::string nextTurn(std::pair<CommandType, CommandType> commands);

	// Returns the Cell grid
	std::vector<std::vector<Cell>> &getGrid();

	// Returns the value of won
	bool isWon() const;

	// Returns the floor number
	unsigned int getFloorCount() const;

	// Removes all sprites from grid
	void clear();

	~GameMap();
};

#endif
