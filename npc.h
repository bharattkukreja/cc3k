#ifndef __NPC_H_
#define __NPC_H_

#include "character.h"
#include <utility>

class PC;

class NPC : public Character {
    unsigned int goldDropped;
 protected:
    void setGoldDropped(const unsigned int gdNew); // protected because it's important for NPC's subclasses to set with operator=, nothing else public:
 public:
    virtual bool isHostile() const = 0;
    unsigned int getGoldDropped() const;

    virtual std::pair<bool,int> hit(PC & target); // not const because some subclasses might change their state this way

    bool isNPC() const override;

    NPC(const unsigned int hp, const unsigned int atk, const unsigned int def, const unsigned int goldDropped);
    NPC(const NPC & other);
    virtual ~NPC() = 0;
};

#endif
