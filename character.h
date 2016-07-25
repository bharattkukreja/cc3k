#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "sprite.h"

class Character : public Sprite {
 protected:
    unsigned int maxHP, hp, atk, def;
 public:
    virtual unsigned int getHit(const unsigned int vsAtk); // getting hit by attacks reduces HP
    
    unsigned int getHP() const;
    unsigned int getAtk() const;
    unsigned int getDef() const;
 
    // nothing needs to directly set HP, atk, or def -- all mutations are changes to the existing value
    void changeHP(const int amount); // changes hp by amount, to a minimum of 0 and a maximum of maxHP
    void changeAtk(const int amount); // changes atk by amount, to a minimum of 1
    void changeDef(const int amount); // changes def by amount, to a minimum of 1

    Character(unsigned int hp, unsigned int atk, unsigned int def);
    Character(const Character & other);

    virtual ~Character() = 0;
};

void changeAttr(unsigned int & attribute, const int amount, const int minValue); // changes an attribute by amount, bounded below by minValue

#endif
