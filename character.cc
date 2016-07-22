#include "sprite.h"
#include "character.h"
#include <cmath>
using namespace std;

Character::Character(unsigned int hp, unsigned int atk, unsigned int def): hp{hp}, atk{atk}, def{def} {}

Character::Character(const Character & other): hp{other.getHP()}, atk{other.getAtk()}, def{other.getDef()} {}

int Character::getHP() { return hp; }

int Character::getAtk() { return atk; }

int Character::getDef() { return def; }

bool strike(int attack, Character & target) {
    target.getHit(attack);
    return true;
}

virtual void getHit(int vsAtk) {
    int damage = (vsAtk*100) / (100+def) + ((vsAtk*100) % (100+def) > 0);
    changeAttr(hp, -damage, 0);
}

void changeAttr(unsigned int & attribute, const int amount, const int minValue) { attribute = max(minValue, attribute + amount); }

void Character::changeAtk(const int amount) { changeAttr(atk, amount, 1); }

void Character::changeDef(const int amount) { changeAttr(def, amount, 1); }
