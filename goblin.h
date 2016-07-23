#ifndef __GOBLIN_H_
#define __GOBLIN_H_

#include "npc.h"

class Goblin : public NPC {
 public:
    Goblin();
    Goblin(const Goblin & other);
    Goblin & operator=(const Goblin & other);
    ~Goblin();
    // note that we would just override hit() to steal gold
};

#endif
