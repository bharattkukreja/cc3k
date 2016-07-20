#ifndef _CELL_HEADER_
#define _CELL_HEADER_

#include <vector>
#include <unique_ptr>
#include <shared_ptr>

// This class implement Cells in the GameMap grid, determining the location of Sprites

enum CellType {Floor, Door, Passage, Wall_horizontal, Wall_vertical, Space};

class Cell {

	std::vector<std::unique_ptr<Cell>> observers;
	CellType type;
	std::shared_ptr<Sprite> sprite;

   public:

	Cell(CellType type);

	// Method called by other cells this cell observes to notify this one
	//    that a PC is in proximity
	void notify();

	// Method to notify all this Cell's observers that a PC is in proximity
	void notifyAll();

	// Method to add a Cell as an observer
	void attach(std::unique_ptr<Cell>);

	// Method to return the type of the Cell
	//   see the CellType enum for the different kinds
	CellType getType() const;

	// Returns whether or not this Cell's sprite is a nullptr
	bool isEmpty() const;

	~Cell();

};

#endif
