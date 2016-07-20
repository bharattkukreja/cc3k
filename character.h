#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "sprite.h"

class Character : public Sprite {
    unsigned int hp, atk, def;
 public:
    virtual void getHit(int vsAtk);
    int getHP() const;
    int getAtk() const;
    int getDef() const;
};

bool stike(int attack, Character & target);

#endif
