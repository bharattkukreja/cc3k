#ifndef __VAMPIRE_H_
#define __VAMPIRE_H_

#include "npc.h"

enum class SpriteType;

class Vampire : public NPC {
 public:
    SpriteType getType() const override;

    bool isHostile() const override;

    Vampire();
    Vampire(const Vampire & other);
    Vampire & operator=(const Vampire & other);
    ~Vampire();
};

#endif
