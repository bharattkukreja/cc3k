#include "goblin.h"
#include "npc.h"
#include "spritetype.h"
using namespace std;

const int goblinHP = 70;
const int goblinAtk = 5;
const int goblinDef = 10;
const bool goblinHostile = true;
const int goblinGold = 1;

bool Goblin::isHostile() const { return goblinHostile; }


Goblin::Goblin(): NPC{goblinHP, goblinAtk, goblinDef, goblinGold} {}

Goblin::Goblin(const Goblin & other): NPC{other} {}

Goblin & Goblin::operator=(const Goblin & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    atk = other.atk;
    def = other.def;
    return *this;
}

Goblin::~Goblin() {};


SpriteType Goblin::getType() const { return SpriteType::Goblin; }
