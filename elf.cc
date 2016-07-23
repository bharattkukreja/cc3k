#include "elf.h"
using namespace std;

extern const unsigned int humanHP, humanAtk, humanDef;

Elf::Elf(): PC{humanHP, humanAtk, humanDef, 0} {}

Elf::Elf(const Elf & other): PC{other} {}

Elf & Elf::operator=(const Elf & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
}
