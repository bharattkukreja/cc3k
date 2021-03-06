#include "pc.h"
#include "orc.h"
#include "spritetype.h"
using namespace std;

int Orc::getGold() const { return gold / 2; }


SpriteType Orc::getType() const { return SpriteType::Orc; }


const int orcHP = 180, orcAtk = 35, orcDef = 25;

Orc::Orc(): PC{orcHP, orcAtk, orcDef} {}

Orc::Orc(const Orc & other): PC{other} {}

Orc & Orc::operator=(const Orc & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
    return *this;
}

Orc::~Orc() {};
