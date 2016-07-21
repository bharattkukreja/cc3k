#ifndef _GAME_MAP_HEADER_
#define _GAME_MAP_HEADER_

#include <vector>
#include <utility>
#include "commands.h"

class Cell;
class Sprite;
class PC;
class AI;

// This is the GameMap class. This class stores and manages the Cell grid,
//   and Sprite interactions.
class GameMap {

	std::vector<std::vector<Cell>> grid; // This is the grid of Cells
	bool won;
	std::pair<int, int> player_location;
	std::vector<std::pair<int, int>> enemy_locations;
	std::vector<Sprite> sprites;
	std::unique_ptr<PC> hero;
	unsigned int floor_count;

	// Populates the grid, i.e. spawns all Sprites
	//    Called by initialize(...)
	void populate();

	// Sets up the grid, i.e. constructs all Cells
	//    Called by initialize(...)
	void setUpMap();

	// static constants
	static const unsigned int width;
	static const unsigned int height;
	
   public:

	GameMap();

	// Initializes the grid
	void initialize(std::unique_ptr<Sprite> &hero);

	// Adjusts state to reflect effects of next turn of the game
	void nextTurn(std::pair<CommandType, CommandType> &commands);

	// Returns the Cell grid
	std::vector<std::vector<Cell>> getGrid() const;

	// Returns the value of won
	bool isWon() const;

	// Returns the floor number
	unsigned int getFloorCount() const;

	// Removes all sprites from grid
	void clear();

	~GameMap();
};

#endif
