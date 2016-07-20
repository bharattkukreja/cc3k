#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "spritetype.h"
#include "sprite.h"
#include "character.h"
#include "pc.h"

class NPC : public Character {
    unsigned int goldDropped;
 public:
    bool hostile;
    bool isNPC() override;
    int getGoldDropped() const;
    virtual bool hit(PC & target);
};

#endif
