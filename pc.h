#ifndef __PC_H_
#define __PC_H_

#include "character.h"

class NPC;

class PC : public Character {
    unsigned int baseHP, baseAtk, baseDef;
 protected:
    unsigned int gold;
 public:
    bool isPC() override;
    virtual bool hit(NPC & target);
    virtual void resetPotions();
    virtual void changeGold(const int amount);
    virtual int score() const;
};

#endif
