#include "pc.h"
#include "dwarf.h"
#include "spritetype.h"
using namespace std;

const int dwarfHP = 100, dwarfAtk = 20, dwarfDef = 30;


SpriteType Dwarf::getType() const { return SpriteType::Dwarf; }


int Dwarf::getGold() const { return 2 * gold; }


Dwarf::Dwarf(): PC{dwarfHP, dwarfAtk, dwarfDef} {}

Dwarf::Dwarf(const Dwarf & other): PC{other} {}

Dwarf & Dwarf::operator=(const Dwarf & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
    return *this;
}

Dwarf::~Dwarf() {};
