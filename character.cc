#include "sprite.h"
#include "character.h"
#include "minmax.h"
using namespace std;

int Character::getHP() { return hp; }

int Character::getAtk() { return atk; }

int Character::getDef() { return def; }

bool strike(int attack, Character & target) {
    target.getHit(attack);
    return true;
}

virtual void getHit(int vsAtk) {
    hp = max(0, hp - max(1, vsAtk - def));
}


