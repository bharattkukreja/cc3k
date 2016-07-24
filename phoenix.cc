#include "phoenix.h"
#include "spritetype.h"
using namespace std;

const unsigned int phoenixHP = 50;
const unsigned int phoenixAtk = 25;
const unsigned int phoenixDef = 25;
const bool phoenixHostile = true;
const unsigned int phoenixGold = 1;

Phoenix::Phoenix(): NPC{phoenixHP, phoenixAtk, phoenixDef, phoenixGold, phoenixHostile} {}

Phoenix::Phoenix(const Phoenix & other): NPC{other} {}

Phoenix & Phoenix::operator=(const Phoenix & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    this->setHostile(other.isHostile());
    atk = other.atk;
    def = other.def;
    return *this;
}

Phoenix::~Phoenix() {};


SpriteType Phoenix::getType() const { return SpriteType::Phoenix; }
