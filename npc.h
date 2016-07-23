#ifndef __NPC_H_
#define __NPC_H_

#include "character.h"

class PC;

class NPC : public Character {
 protected:
    unsigned int goldDropped;
    bool hostile;
 public:
    bool isHostile();
    void setHostile(const bool newHostile);
    bool isNPC() const override;
    unsigned int getGoldDropped() const;
    virtual bool hit(PC & target);

    NPC(const unsigned int hp, const unsigned int atk, const unsigned int def, const unsigned int goldDropped, const bool hostile);
    NPC(const NPC & other);
    ~NPC();
};

#endif
