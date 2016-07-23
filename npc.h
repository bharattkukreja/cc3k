#ifndef __NPC_H_
#define __NPC_H_

#include "character.h"

class PC;

class NPC : public Character {
    unsigned int goldDropped;
    bool hostile;
 public:
    bool isHostile();
    void setHostile(const bool newHostile);
    bool isNPC() const override;
    int getGoldDropped() const;
    virtual bool hit(PC & target);
};

#endif
