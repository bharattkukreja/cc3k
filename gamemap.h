#ifndef _GAME_MAP_HEADER_
#define _GAME_MAP_HEADER_

#include <vector>
#include <pair>
#include <commands.h>

class Cell;

// This is the GameMap class. This class stores and manages the Cell grid,
//   and Sprite interactions.
class GameMap {

	std::vector<std::vector<Cell>> grid; // This is the grid of Cells
	bool won;
	pair<int, int> player_location;
	vector<pair<int, int>> enemy_locations;

	// Populates the grid, i.e. spawns all Sprites
	// Called by init()
	void populate();

	// static constants
	static const unsigned int width;
	static const unsigned int height;
	
   public:

	GameMap();

	// Initializes the grid
	void initialize();

	// Adjusts state to reflect effects of next turn of the game
	void nextTurn(CommandType c_type);

	// Returns the Cell grid
	std::vector<std::vector<Cell>> getGrid() const;

	// Returns the value of won
	bool isWon() const;

	~GameMap();
};

#endif
