#ifndef __NPC_H_
#define __NPC_H_

#include "character.h"

class PC;

class NPC : public Character {
    unsigned int goldDropped;
    bool hostile;
 public:
    bool getHostile();
    void setHostile(const bool newHostile);
    bool isNPC() override;
    int getGoldDropped() const;
    virtual bool hit(PC & target);
};

#endif
