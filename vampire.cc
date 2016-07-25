#include "vampire.h"
#include "spritetype.h"
using namespace std;

const unsigned int vampireHP = 50;
const unsigned int vampireAtk = 25;
const unsigned int vampireDef = 25;
const bool vampireHostile = true;
const unsigned int vampireGold = 1;

bool Vampire::isHostile() const { return vampireHostile; }


Vampire::Vampire(): NPC{vampireHP, vampireAtk, vampireDef, vampireGold} {}

Vampire::Vampire(const Vampire & other): NPC{other} {}

Vampire & Vampire::operator=(const Vampire & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    atk = other.atk;
    def = other.def;
    return *this;
}

Vampire::~Vampire() {};


SpriteType Vampire::getType() const { return SpriteType::Vampire; }
