#include "sprite.h"
#include "character.h"
using namespace std;

Character::Character(const int hp, const int atk, const int def): maxHP{hp}, hp{hp}, atk{atk}, def{def} {}

Character::Character(const Character & other): maxHP{other.maxHP}, hp{other.hp}, atk{other.hp}, def{other.def} {}

Character::~Character() {}


int Character::getHP() const { return hp; }

int Character::getAtk() const { return atk; }

int Character::getDef() const { return def; }


int max(const int a, const int b) {return a > b ? a : b; } // because it wasn't in cmath


void changeAttr(int & attribute, const int amount, const int minValue) { attribute = max(minValue, amount + attribute); }


void Character::changeHP(const int amount) {
    changeAttr(hp, amount, 0);
    if (hp > maxHP) { // bounds the amount a potion can heal
        hp = maxHP;
    }
}

void Character::changeAtk(const int amount) { changeAttr(atk, amount, 1); }

void Character::changeDef(const int amount) { changeAttr(def, amount, 1); }


int Character::getHit(const int vsAtk) { 
    unsigned int damage = (vsAtk*100) / (100+def) + ((vsAtk*100) / (100+def) > 0);
    changeHP(-damage);
    return damage;
}
