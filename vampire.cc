#include "goblin.h"
#include "npc.h"
#include "character.h"
using namespace std;

const int goblinHP = 70;
const int goblinAtk = 5;
const int goblinDef = 10;
const bool goblinHostile = true;
const int goblinGold = 1;

Goblin::Goblin(): hp{goblinHP}, atk{goblinAtk}, def{goblinDef}, hostile{goblinHostile}, goldDropped{goblinGold} {}
Goblin::Goblin(const Goblin & other): hp{other.hp}, atk{goblinAtk}, def{goblinDef}, hostile{other.hostile}, goldDropped{other.goldDropped} {}

Goblin & Goblin::operator=(const Goblin & other) {
    hp = other.hp;
    goldDropped = other.goldDropped;
    hostile = other.hostile;
    atk = other.atk;
    def = other.def;
}

Goblin::~Goblin() {};
