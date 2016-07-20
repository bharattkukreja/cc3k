#ifndef __PC_H_
#define __PC_H_

#include "sprite"
#include "character.h"
#include "spritetype.h"
#include "npc.h"

class PC : public Character {
    unsigned int baseHP, baseAtk, baseDef;
 protected:
    unsigned int gold;
 public:
    bool isPC() override;
    virtual bool hit(NPC & target);
    virtual void resetPotions();
    virtual void changeGold(const int amount);
    virtual void changeHP(const int amount);
    virtual void changeAtk(const int amount);
    virtual void changeDef(const int amount);
    virtual void drink(Potion & p);
    virtual int score() const;
};

void changeAttr(unsigned int & attribute, const int amount, const int minValue);

#endif
