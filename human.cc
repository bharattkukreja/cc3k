#include "character.h"
#include "pc.h"
#include "human.h"
using namespace std;

int Human::score() {
    return 2 * gold;
}

extern const unsigned int humanHP, humanAtk, humanDef;

Human::Human(): PC{humanHP, humanAtk, humanDef} {}

Human::Human(const Human & other): PC{other} {}

Human & Human::operator=(const Human & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
    return *this;
}
