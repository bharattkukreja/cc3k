#include <vector>
#include <unique_ptr>
#include <shared_ptr>
#include "cell.h"
using namespace std;

// This is the implementation for the Cell class, see cell.h for documentation

Cell::Cell(CellType type) : type{type} {}

void Cell::notify(Cell &a_cell) {
	if(sprite != nullptr && a_cell.sprite!=nullptr && 
		a_cell.sprite.isPC() && sprite.isNPC() && sprite.isHostile()){
		
	}
}

void Cell::notifyAll() {
	for(auto observer: observers){
		observer.notify(*this);
	}
}

void Cell::attach(unique_ptr<Cell> observer) {
	observers.add(observer);
}

CellType Cell::getType() const {
	return type;
}

bool Cell::isEmpty() const {
	return (sprite == null);
}

Cell::~Cell() {}
