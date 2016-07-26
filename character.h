#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "sprite.h"

class Character : public Sprite {
 protected:
    int maxHP, hp, atk, def;
 public:
    virtual int getHit(const int vsAtk); // getting hit by attacks reduces HP

    int getHP() const;
    int getAtk() const;
    int getDef() const;
 
    // nothing needs to directly set HP, atk, or def -- all mutations are changes to the existing value
    void changeHP(const int amount); // changes hp by amount, to a minimum of 0 and a maximum of maxHP
    void changeAtk(const int amount); // changes atk by amount, to a minimum of 1
    void changeDef(const int amount); // changes def by amount, to a minimum of 1

    Character(int hp, int atk, int def);
    Character(const Character & other);

    virtual ~Character() = 0;
};

void changeAttr(int & attribute, const int amount, const int minValue); // changes an attribute by amount, bounded below by minValue

#endif
