#include "pc.h"
#include "dwarf.h"
using namespace std;

const unsigned int dwarfHP = 100, dwarfAtk = 20, dwarfDef = 30;

int Dwarf::getGold() const override { return 2 * gold; }

Dwarf::Dwarf(): PC{humanHP, humanAtk, humanDef} {}

Dwarf::Dwarf(const Dwarf & other): PC{other} {}

Dwarf & Dwarf::operator=(const Dwarf & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
    return *this;
}

Dwarf::~Dwarf() {};
