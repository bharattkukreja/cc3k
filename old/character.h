#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "sprite.h"

class Character : public Sprite {
 protected:
    unsigned int hp, atk, def;
 public:
    virtual void getHit(int vsAtk);
    int getHP() const;
    int getAtk() const;
    int getDef() const;
    Character(unsigned int hp, unsigned int atk, unsigned int def);
    Character(const Character & other);
    void changeAtk(const int amount); // changes atk by amount, to a minimum of 1
    void changeDef(const int amount); // changes def by amount, to a minimum of 1
};

bool stike(int attack, Character & target);

void changeAttr(unsigned int & attribute, const int amount, const int minValue);

#endif
