#include "troll.h"
#include "spritetype.h"
using namespace std;

const unsigned int trollHP = 120;
const unsigned int trollAtk = 25;
const unsigned int trollDef = 15;
const bool trollHostile = true;
const unsigned int trollGold = 1;

Troll::Troll(): NPC{trollHP, trollAtk, trollDef, trollGold, trollHostile} {}

Troll::Troll(const Troll & other): NPC{other} {}

Troll & Troll::operator=(const Troll & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    this->setHostile(other.isHostile());
    atk = other.atk;
    def = other.def;
    return *this;
}

Troll::~Troll() {};


SpriteType Troll::getType() const { return SpriteType::Troll; }
