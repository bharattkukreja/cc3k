#include "phoenix.h"
#include "spritetype.h"
using namespace std;

const int phoenixHP = 50;
const int phoenixAtk = 25;
const int phoenixDef = 25;
const bool phoenixHostile = true;
const int phoenixGold = 1;

bool Phoenix::isHostile() const { return phoenixHostile; }


Phoenix::Phoenix(): NPC{phoenixHP, phoenixAtk, phoenixDef, phoenixGold} {}

Phoenix::Phoenix(const Phoenix & other): NPC{other} {}

Phoenix & Phoenix::operator=(const Phoenix & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    atk = other.atk;
    def = other.def;
    return *this;
}

Phoenix::~Phoenix() {};


SpriteType Phoenix::getType() const { return SpriteType::Phoenix; }
