#ifndef __DRAGON_H_
#define __DRAGON_H_

#include "npc.h"

enum class SpriteType;

class Dragon : public NPC {
 public:
    bool isHostile() const override;

    SpriteType getType() const override;

    Dragon();
    Dragon(const Dragon & other);
    Dragon & operator=(const Dragon & other);
    ~Dragon();
};

#endif
