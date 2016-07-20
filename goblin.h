#ifndef __GOBLIN_H_
#define __GOBLIN_H_

#include "npc.h"

const int goblinHP = 70;
const int goblinAtk = 5;
const int goblinDef = 10;
const bool goblinHostile = true;
const int goblinGold = 1;

class Goblin : public NPC {
 public:
    Goblin(): hp{goblinHP}, atk{goblinAtk}, def{goblinDef}, hostile{goblinHostile}, goldDropped{goblinGold} {}
    Goblin(const Goblin & other): hp{other.hp}, atk{goblinAtk}, def{goblinDef}, hostile{other.hostile}, goldDropped{other.goldDropped} {}
    Goblin & operator=(const Goblin & other);
    ~Goblin() {};
    // note that we would just override hit() to steal gold
};

#endif
