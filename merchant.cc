#include "merchant.h"
#include "spritetype.h"
using namespace std;

const unsigned int merchantHP = 30;
const unsigned int merchantAtk = 70;
const unsigned int merchantDef = 5;
bool merchantHostile = false;
const unsigned int merchantGold = 4;

Merchant::Merchant(): NPC{merchantHP, merchantAtk, merchantDef, merchantGold, merchantHostile} {}

Merchant::Merchant(const Merchant & other): NPC{other} {}

Merchant & Merchant::operator=(const Merchant & other) {
    hp = other.hp;
    goldDropped = other.goldDropped;
    hostile = other.hostile;
    atk = other.atk;
    def = other.def;
    return *this;
}

Merchant::~Merchant() {};

// merchants, when set to hostile, all become hostile from then on
void Merchant::setHostile(const bool newHostile) {
    merchantHostile = hostile = newHostile;
}


SpriteType Merchant::getType() const { return SpriteType::Merchant; }
