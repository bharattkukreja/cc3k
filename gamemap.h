#ifndef _GAME_MAP_HEADER_
#define _GAME_MAP_HEADER_

#include <vector>
#include <pair>

class Cell;

// This is the GameMap class. This class stores and manages the Cell grid,
//   and Sprite interactions.
class GameMap {

	std::vector<std::vector<Cell>> grid; // This is the grid of Cells
	//bool won;

	// Populates the grid, i.e. spawns all Sprites
	// Called by init()
	void populate();
	
   public:

	GameMap();

	// Initializes the grid
	void initialize();

	// Returns the Cell grid
	//std::vector<std::vector<Cell>> getGrid() const;

	// Returns the value of won
	//bool isWon() const;

	~GameMap();
};

#endif
