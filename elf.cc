#include "elf.h"
using namespace std;

const unsigned int elfHP = 140, humanAtk = 30, humanDef = 10;

Elf::Elf(): PC{humanHP, humanAtk, humanDef, 0} {}

Elf::Elf(const Elf & other): PC{other} {}

Elf & Elf::operator=(const Elf & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
}

Elf::~Elf() {};
