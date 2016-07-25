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
    this->setGoldDropped(other.getGoldDropped());
    this->setHostile(other.isHostile());
    atk = other.atk;
    def = other.def;
    return *this;
}

Merchant::~Merchant() {};


unsigned int Merchant::getHit(const unsigned int vsAtk) {
    unsigned int damage = (vsAtk*100) / (100+def) + ((vsAtk*100) / (100+def) > 0);
    changeHP(-damage);
    this->setHostile(true);
    merchantHostile = true; // merchants, when hit, all become hostile forever
    return damage;
}


SpriteType Merchant::getType() const { return SpriteType::Merchant; }
