#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "sprite.h"

class Character : public Sprite {
 protected:
    unsigned int hp, atk, def;
 public:
    virtual void getHit(int vsAtk);
    int getHP() const;
};

bool stike(int attack, Character & target);

#endif
