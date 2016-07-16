#include <vector>
#include "gamemap.h"
#include "cell.h"

// Implementation of GameMap class, see gamemap.h for documentation

// static constants

const unsigned int GameMap::width = 79;
const unsigned int GameMap::height = 30;

// Methods

GameMap::GameMap(){}

void GameMap::initialize(SpriteType pc_type){
	for(int r=0; r<width; r++){
		grid[r] = vector<Cell>;
		for(int c=0; c<height; c++){
			grid[r][c] = Cell(CellType::Floor);
		}
	}
}

vector<vector<Cell>> GameMap::getGrid() const {
	return grid;
}

bool GameMap::isWon() const {
	return won;
}

GameMap::~GameMap(){}
