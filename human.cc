#include "character.h"
#include "pc.h"
#include "human.h"
using namespace std;

int Human::score() const { return 1.5 * this->getGold(); }

const unsigned int humanHP = 140, humanAtk = 25, humanDef = 25;

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
