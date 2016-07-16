#include <vector>
#include <unique_ptr>
#include <shared_ptr>
#include "cell.h"

// This is the implementation for the Cell class, see cell.h for documentation

Cell::Cell(CellType type) : type{type} {}

void Cell::notify(Cell &a_cell) {}

void Cell::notifyAll() {}

void Cell::attach() {}

CellType Cell::getType() const {
	return type;
}

Cell::~Cell() {}
