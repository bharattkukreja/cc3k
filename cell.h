#ifndef _CELL_HEADER_
#define _CELL_HEADER_

#include <vector>
#include <memory>

// This class implement Cells in the GameMap grid, determining the location of Sprites

enum CellType {Floor, Door, Passage, Wall_horizontal, Wall_vertical, Space};

class Sprite;

class Cell {

	std::vector<Cell*> observers;
	CellType type;

	bool attacked;
	unsigned int y, x;
	
   public:

        std::shared_ptr<Sprite> sprite;

	explicit Cell(CellType type, unsigned int y, unsigned int x);

	// Method called by other cells this cell observes to notify this one
	//    that a PC is in proximity
	void notify(Cell &a_cell);

	// Method to notify all this Cell's observers that a PC is in proximity
	void notifyAll();

	// Method to add a Cell as an observer
	void attach(Cell &observer);

	// Method to get the observers of a cell
        std::vector<Cell*> getObservers();

	// Method to remove all observers of a cell
	void clear();

	// Method to return the type of the Cell
	//   see the CellType enum for the different kinds
	CellType getType() const;

	// Method to set the Type of the Cell
	//   see the CellType enum for the different kinds
	void setType(CellType type);

	// Returns whether or not this Cell's sprite is a nullptr
	bool isEmpty() const;

	// Returns whether or not the cell's sprite just attacked a PC
	bool hasAttacked();

	// Returns this cell's row in the Grid
	unsigned int getRow() const;

	// Returns this cell's column in the Grid
	unsigned int getCol() const;

	~Cell();

};

#endif
