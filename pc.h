#ifndef __PC_H_
#define __PC_H_

#include "character.h"
#include <utility>

class NPC;

class PC : public Character {
    int baseAtk, baseDef; // base values allow easy reset of changes made by potions. maxHP bounds their effect
 protected:
    int gold; // players can pick up money, which goes here!
 public:
    PC(int HP, int atk, int def);
    PC(const PC & other);
    PC & operator=(const PC & other);
    virtual ~PC() = 0;

    bool isPC() const override;

    virtual int getGold() const;

    virtual std::pair<bool, int> hit(NPC & target); // by default, this just calls strike() from character.h
    virtual void resetPotions(); // resets the effects of atk/def potions
    virtual void changeGold(const int amount); // changes (usually adds) gold
    virtual int score() const;
};

#endif
