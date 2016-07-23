#include "goblin.h"
#include "npc.h"
#include "character.h"
using namespace std;

const unsigned int goblinHP = 70;
const unsigned int goblinAtk = 5;
const unsigned int goblinDef = 10;
const bool goblinHostile = true;
const unsigned int goblinGold = 1;

Goblin::Goblin(): NPC{goblinHP, goblinAtk, goblinDef, goblinGold, goblinHostile} {}

Goblin::Goblin(const Goblin & other): NPC{other} {}

Goblin & Goblin::operator=(const Goblin & other) {
    hp = other.hp;
    goldDropped = other.goldDropped;
    hostile = other.hostile;
    atk = other.atk;
    def = other.def;
    return *this;
}

Goblin::~Goblin() {};
