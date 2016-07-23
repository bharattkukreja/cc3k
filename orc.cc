#include "pc.h"
#include "orc.h"
using namespace std;

int Orc::getGold() const override { return gold / 2; }

const unsigned int orcHP = 180, orcAtk = 35, orcDef = 25;

Orc::Orc(): PC{humanHP, humanAtk, humanDef} {}

Orc::Orc(const Orc & other): PC{other} {}

Orc & Orc::operator=(const Orc & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
    return *this;
}

Orc::~Orc() {};
