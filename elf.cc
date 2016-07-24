#include "pc.h"
#include "elf.h"
#include "spritetype.h"
using namespace std;

const unsigned int elfHP = 140, elfAtk = 30, elfDef = 10;


SpriteType Elf::getType() const { return SpriteType::Elf; }


bool Elf::isElf() const { return true; }


Elf::Elf(): PC{elfHP, elfAtk, elfDef} {}

Elf::Elf(const Elf & other): PC{other} {}

Elf & Elf::operator=(const Elf & other) {
    hp = other.hp;
    gold = other.gold;
    atk = other.atk;
    def = other.def;
    return *this;
}

Elf::~Elf() {};
