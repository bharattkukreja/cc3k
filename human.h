#ifndef __HUMAN_H_
#define __HUMAN_H_

#include "spritetype.h"
#include "sprite.h"
#include "character.h"
#include "pc.h"

const unsigned int humanHP = 140, humanAtk = 25, humanDef = 25;

class Human : public PC {
 public:
    int score() const override;
    Human();
    Human(const Human & other);
    Human & operator=(const Human & other);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient
    ~Human() {};
};

#endif
