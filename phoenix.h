#ifndef __PHOENIX_H_
#define __PHOENIX_H_

#include "npc.h"

enum class SpriteType;

class Phoenix : public NPC {
 public:
    SpriteType getType() const override;

    Phoenix();
    Phoenix(const Phoenix & other);
    Phoenix & operator=(const Phoenix & other);
    ~Phoenix();
};

#endif
