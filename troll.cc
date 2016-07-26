#include "troll.h"
#include "spritetype.h"
using namespace std;

const int trollHP = 120;
const int trollAtk = 25;
const int trollDef = 15;
const bool trollHostile = true;
const int trollGold = 1;

bool Troll::isHostile() const { return trollHostile; }


Troll::Troll(): NPC{trollHP, trollAtk, trollDef, trollGold} {}

Troll::Troll(const Troll & other): NPC{other} {}

Troll & Troll::operator=(const Troll & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    atk = other.atk;
    def = other.def;
    return *this;
}

Troll::~Troll() {};


SpriteType Troll::getType() const { return SpriteType::Troll; }
