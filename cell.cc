#include <vector>
#include <memory>
#include "npc.h"
#include "cell.h"
#include "pc.h"
#include "sprite.h"

#include <iostream>

using namespace std;

// This is the implementation for the Cell class, see cell.h for documentation

Cell::Cell(CellType type, unsigned int y, unsigned int x) : type{type}, attacked{false}, y{y}, x{x}, sprite{nullptr} {}

void Cell::notify(Cell &a_cell) {
	if(sprite != nullptr && a_cell.sprite!=nullptr && 
		a_cell.sprite->isPC() && sprite->isNPC() && (dynamic_pointer_cast<NPC>(sprite))->isHostile()){
		(dynamic_pointer_cast<NPC>(sprite))->hit(*dynamic_pointer_cast<PC>(a_cell.sprite));
		attacked = true;
	}
}

bool Cell::hasAttacked() {
	bool temp = attacked;
	attacked = false;
	return temp;
}

void Cell::notifyAll() {
	for(auto observer: observers){
		observer->notify(*this);
	}
}

void Cell::attach(Cell &observer) {
	observers.emplace_back(&observer);
}

vector<Cell*> Cell::getObservers(){
	return observers;
}

void Cell::clear(){
	observers.clear();
}

CellType Cell::getType() const {
	return type;
}

void Cell::setType(CellType type) {
	this->type = type;
}

bool Cell::isEmpty() const {
	return (sprite == nullptr);
}

unsigned int Cell::getCol() const {
	return x;
}

unsigned int Cell::getRow() const {
	return y;
}

Cell::~Cell() {
	observers.clear();
}
