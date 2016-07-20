#include "spritetype.h"
#include "sprite.h"
#include "character.h"
#include "pc.h"
using namespace std;

int Human::score() {
    return 2 * gold;
}

Human & Human::operator=(const Human & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
}
