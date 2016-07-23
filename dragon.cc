#include "dragon.h"
using namespace std;

const unsigned int dragonHP = 150;
const unsigned int dragonAtk = 20;
const unsigned int dragonDef = 20;
const bool dragonHostile = false; // individual dragons become hostile when you get close, but other dragons remain
const unsigned int dragonGold = 1;

Dragon::Dragon(): NPC{dragonHP, dragonAtk, dragonDef, dragonGold, dragonHostile} {}

Dragon::Dragon(const Dragon & other): NPC{other} {}

Dragon & Dragon::operator=(const Dragon & other) {
    hp = other.hp;
    goldDropped = other.goldDropped;
    hostile = other.hostile;
    atk = other.atk;
    def = other.def;
    return *this;
}

Dragon::~Dragon() {};
