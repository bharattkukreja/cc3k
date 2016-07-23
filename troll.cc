#include "troll.h"
using namespace std;

const unsigned int trollHP = 120;
const unsigned int trollAtk = 25;
const unsigned int trollDef = 15;
const bool trollHostile = true;
const unsigned int trollGold = 1;

Troll::Troll(): NPC{trollHP, trollAtk, trollDef, trollGold, trollHostile} {}

Troll::Troll(const Troll & other): NPC{other} {}

Troll & Troll::operator=(const Troll & other) {
    hp = other.hp;
    goldDropped = other.goldDropped;
    hostile = other.hostile;
    atk = other.atk;
    def = other.def;
    return *this;
}

Troll::~Troll() {};
