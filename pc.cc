#include "pc.h"
#include "npc.h"
#include <utility>
using namespace std;

PC::PC(const unsigned int hp, const unsigned int atk, const unsigned int def): Character{hp, atk, def}, baseAtk{atk}, baseDef{def}, gold{0} {}

PC::PC(const PC & other): Character{other}, baseAtk{other.baseAtk}, baseDef{other.baseDef}, gold{other.gold} {}

PC::~PC() {}


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

pair<bool,int> PC::hit(NPC & target) {
    int damage = target.getHit(atk);
    pair<bool, int> info = make_pair(true, damage);
    return info;
}

int PC::getGold() const { return gold; }

void PC::changeGold(const int amount) { changeAttr(gold, amount, 0); }

int PC::score() const { return this->getGold(); }
