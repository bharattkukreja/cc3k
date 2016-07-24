#ifndef __GOBLIN_H_
#define __GOBLIN_H_

#include "npc.h"

enum class SpriteType;

class Goblin : public NPC {
 public:
    SpriteType getType() const override;

    Goblin();
    Goblin(const Goblin & other);
    Goblin & operator=(const Goblin & other);
    ~Goblin();
    // note that we would just override hit() to steal gold
};

#endif
