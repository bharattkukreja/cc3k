#include <vector>
#include <unique_ptr>
#include "gamemap.h"
#include "cell.h"

// Implementation of GameMap class, see gamemap.h for documentation

// static constants

const unsigned int GameMap::width = 79;
const unsigned int GameMap::height = 30;

// Methods

GameMap::GameMap(){}

void populate() {

}

void GameMap::initialize(unique_ptr<PC hero>){
	for(int r=0; r<width; r++){
		grid[r] = vector<Cell>;
		for(int c=0; c<height; c++){
			grid[r][c] = Cell(CellType::Floor);
			if(r>0 && grid[r-1][c].getType()!=CellType::Wall 
			       && grid[r][c].getType()!=CellType::Wall){
				grid[r-1][c].attach(grid[r][c]);		
				grid[r][c].attach(grid[r-1][c]);
			}
			if(c>0 && grid[r][c-1].getType()!=CellType::Wall
                               && grid[r][c].getType()!=CellType::Wall){
				grid[r][c-1].attach(grid[r][c]);
				grid[r][c].attach(grid[r][c-1]);
			}
		}
	}
	
	populate();
}

void GameMap::clear(){
	
	for(auto row: grid){
		for(auto cell: grid){
			cell.sprite = nullptr;
		}
	}
}

void GameMap::nextTurn(pair<CommandType c_type, CommandType c_type>){
	
}

vector<vector<Cell>> GameMap::getGrid() const {
	return grid;
}

bool GameMap::isWon() const {
	return won;
}

GameMap::~GameMap(){}
