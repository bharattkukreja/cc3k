#ifndef _GAME_MAP_HEADER_
#define _GAME_MAP_HEADER_

#include <vector>
#include <utility>
#include "commands.h"
#include "cell.h"
#include "ai.h"

class Sprite;
class PC;

// This is the GameMap class. This class stores and manages the Cell grid,
//   and Sprite interactions.
class GameMap {

	std::vector<std::vector<Cell>> grid; // This is the grid of Cells
	std::pair<int, int> player_location;
	std::vector<std::pair<int, int>> enemy_locations;
	std::vector<Sprite> sprites;
	std::shared_ptr<PC> hero;
	AI ai;
	unsigned int floor_count;

	// Populates the grid, i.e. spawns all Sprites
	//    Called by initialize(...)
	void populate();

	// decides direction based on given command pair
	void decideDirection(std::pair<CommandType, CommandType> &c_type, unsigned int & r, unsigned int & c);

	// static constants
	static const unsigned int width;
	static const unsigned int height;
	
   public:

	GameMap();

	// Sets up the cell grid, i.e. constructs all Cells
	//   with a randomized configuration
        void setUpMap();

	// Sets up the grid, i.e. constructs all Cells
        //    with the types given by the CellType grid 'map'
        void setUpMap(std::vector<std::vector<CellType>> &map);

	// Initializes the GameMap
	void initialize(std::shared_ptr<PC> hero);

	// Adjusts state to reflect effects of next turn of the game
	void nextTurn(std::pair<CommandType, CommandType> &commands);

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
