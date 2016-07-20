#include "sprite.h"
#include "character.h"
#include "basicmath.h"
using namespace std;

int Character::getHP() { return hp; }

bool strike(int attack, Character & target) {
    target.getHit(attack);
    return true;
}

virtual void getHit(int vsAtk) {
    int damage = ceil(vsAtk*100/(100+def));
    hp = max(0, hp - damage);
}


