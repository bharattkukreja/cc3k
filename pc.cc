#include "pc.h"
#include "npc.h"
using namespace std;

PC::PC(unsigned int HP, unsigned int atk, unsigned int def): Character{hp, atk, def}, maxHP{HP}, baseAtk{atk}, baseDef{def}, gold{0} {}

PC::PC(const PC & other): Character{other.hp, other.atk, other.def}, maxHP{other.maxHP}, baseAtk{other.baseAtk}, baseDef{other.baseDef}, gold{other.gold} {}

PC & PC::operator=(const PC & other) {
    hp = other.hp; atk = other.atk; def = other.def;
    maxHP = other.maxHP;
    baseAtk = other.baseAtk;
    baseDef = other.baseDef;
    gold = other.gold;
    return *this;
}

bool PC::isPC() const { return true; }

void PC::resetPotions() {
    atk = baseAtk;
    def = baseDef;
}

bool PC::hit(NPC & target) {
    return strike(atk, target);
}

int PC::getGold() const { return gold; }

void PC::changeGold(const int amount) { changeAttr(gold, amount, 0); }

void PC::changeHP(const int amount) {
    if (hp + amount > maxHP) { // bounds the amount a potion can heal
        hp = maxHP;
    } else {
        changeAttr(hp, amount, 0);
    }
}

int PC::score() const { return this->getGold(); }
