#include "werewolf.h"
#include "spritetype.h"
using namespace std;

const unsigned int werewolfHP = 50;
const unsigned int werewolfAtk = 25;
const unsigned int werewolfDef = 25;
const bool werewolfHostile = true;
const unsigned int werewolfGold = 1;

bool Werewolf::isHostile() const { return werewolfHostile; }


Werewolf::Werewolf(): NPC{werewolfHP, werewolfAtk, werewolfDef, werewolfGold} {}

Werewolf::Werewolf(const Werewolf & other): NPC{other} {}

Werewolf & Werewolf::operator=(const Werewolf & other) {
    hp = other.hp;
    this->setGoldDropped(other.getGoldDropped());
    atk = other.atk;
    def = other.def;
    return *this;
}

Werewolf::~Werewolf() {};

SpriteType Werewolf::getType() const { return SpriteType::Werewolf; }
