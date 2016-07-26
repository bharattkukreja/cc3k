#include "pc.h"
#include "human.h"
#include "spritetype.h"
using namespace std;

SpriteType Human::getType() const { return SpriteType::Human; }


int Human::score() const { return 1.5 * this->getGold(); }


const int humanHP = 140, humanAtk = 25, humanDef = 25;

Human::Human(): PC{humanHP, humanAtk, humanDef} {}

Human::Human(const Human & other): PC{other} {}

Human & Human::operator=(const Human & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
    return *this;
}

Human::~Human() {};
