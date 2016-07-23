#ifndef __PC_H_
#define __PC_H_

#include "character.h"

class NPC;

class PC : public Character {
    unsigned int maxHP, baseAtk, baseDef; // base values allow easy reset of changes made by potions. maxHP bounds their effect
    unsigned int gold; // players can pick up money, which goes here!
 public:
    PC(unsigned int HP, unsigned int atk, unsigned int def, unsigned int gold = 0);
    PC(const PC & other);
    bool isPC() const override;

    virtual int getGold() const;

    virtual bool hit(NPC & target); // by default, this just calls strike() from character.h
    virtual void resetPotions(); // resets the effects of atk/def potions
    virtual void changeGold(const int amount); // changes (usually adds) gold
    virtual int score() const;
};

#endif
