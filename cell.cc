#include <vector>
#include <memory>
#include "npc.h"
#include "cell.h"
#include "pc.h"
#include "sprite.h"

using namespace std;

// This is the implementation for the Cell class, see cell.h for documentation

Cell::Cell(CellType type) : type{type}, sprite{nullptr} {}

void Cell::notify(Cell &a_cell) {
	if(sprite != nullptr && a_cell.sprite!=nullptr && 
		a_cell.sprite->isPC() && sprite->isNPC() && (dynamic_pointer_cast<NPC>(sprite))->isHostile()){
		(dynamic_pointer_cast<NPC>(sprite))->hit(*dynamic_pointer_cast<PC>(a_cell.sprite));
	}
}

void Cell::notifyAll() {
	for(auto observer: observers){
		observer->notify(*this);
	}
}

void Cell::attach(Cell &observer) {
	observers.emplace_back(shared_ptr<Cell>(&observer));
}

CellType Cell::getType() const {
	return type;
}

bool Cell::isEmpty() const {
	return (sprite == nullptr);
}

Cell::~Cell() {}
