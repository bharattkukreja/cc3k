#ifndef __HUMAN_H_
#define __HUMAN_H_

#include "spritetype.h"
#include "sprite.h"
#include "character.h"
#include "pc.h"

const int humanHP = 140;
const int humanAtk = 25;
const int humanDef = 25;

class Human : public PC {
 public:
    int score() override;
    Human(): hp{humanHP}, atk{humanAtk}, def{humanDef}, baseHP{humanHP}, baseAtk{humanAtk}, baseDef{humanDef}, gold{0} {}
    Human(const Human & h): hp{h.hp}, atk{h.atk}, def{h.def}, baseAtk{humanDef}, baseDef{humanDef}, gold{h.gold} {}
    Human & operator=(const Human & h);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient
    ~Human() {};
}

#endif
