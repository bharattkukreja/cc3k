#ifndef __TROLL_H_
#define __TROLL_H_

#include "npc.h"

enum class SpriteType;

class Troll : public NPC {
 public:
    SpriteType getType() const override;

    Troll();
    Troll(const Troll & other);
    Troll & operator=(const Troll & other);
    ~Troll();
};

#endif
