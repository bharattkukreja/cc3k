#include "pc.h"
#include "npc.h"
using namespace std;

bool PC::isPC() { return true; }

int PC::resetPotions() {
    atk = baseAtk;
    def = baseDef;
}

bool PC::hit(NPC & target) {
    return strike(atk, target);
}

void changeAttr(unsigned int & attribute, const int amount, const int minValue) {
    if (attribute + amount > minValue) {
        attribute += amount;
    } else {
        attribute = minValue;
    }
}

virtual void PC::changeGold(const int amount) { changeAttr(gold, amount, 0); }

virtual void PC::changeHP(const int amount) {
    if (hp + amount > maxHP) { // bounds the amount a potion can heal
        hp = maxHP;
    } else {
        changeAttr(hp, amount, 0);
    }
}

virtual void PC::changeAtk(const int amount) { changeAttr(atk, amount, 1); }

virtual void PC::changeDef(const int amount) { changeAttr(def, amount, 1); }

virtual int PC::score() { return gold; }
