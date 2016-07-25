#include "dragon.h"
#include "spritetype.h"
using namespace std;

const unsigned int dragonHP = 150;
const unsigned int dragonAtk = 20;
const unsigned int dragonDef = 20;
// not hostile until the player gets within a one-block radius is the same as being hostile & stationary
const bool dragonHostile = true;
const unsigned int dragonGold = 1;

bool Dragon::isHostile() const { return dragonHostile; }


Dragon::Dragon(): NPC{dragonHP, dragonAtk, dragonDef, dragonGold} {}

Dragon::Dragon(const Dragon & other): NPC{other} {}

Dragon & Dragon::operator=(const Dragon & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    atk = other.atk;
    def = other.def;
    return *this;
}

Dragon::~Dragon() {};


SpriteType Dragon::getType() const { return SpriteType::Dragon; }
