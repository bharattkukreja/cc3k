#ifndef __NPC_H_
#define __NPC_H_

#include "character.h"

class PC;

class NPC : public Character {
    unsigned int goldDropped;
    bool hostile;
 protected:
    void setGoldDropped(const unsigned int gdNew); // protected because it's important for NPC's subclasses to set with operator=, nothing else public:
 public:
    bool isHostile() const;
    virtual void setHostile(const bool newHostile);
    bool isNPC() const override;
    unsigned int getGoldDropped() const;
    virtual bool hit(PC & target); // not const because some subclasses might change their state this way

    NPC(const unsigned int hp, const unsigned int atk, const unsigned int def, const unsigned int goldDropped, const bool hostile);
    NPC(const NPC & other);
    virtual ~NPC() = 0;
};

#endif
