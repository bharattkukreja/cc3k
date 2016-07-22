#ifndef __ATKPOT_H_
#define __ATKPOT_H_

#include "potion.h"

class PC;

const int valueAtkPot = 5;

class AtkPot : public Potion {
    static bool visiblePositive, visibleNegative;
 public:
    void use(PC & user) override; // AtkPots change their user's attack
    void getVisible() override; // gets visible based on whether the potion is positive or negative
    explicit AtkPot(const bool positive); // value is a default value and isVisible comes with them
    AtkPot(const AtkPot & other);
    AtkPot & operator=(const AtkPot & other);
    // no move ctor/assignment operator because there are no pointers to move -- it wouldn't be faster.
    ~AtkPot() {};
};

#endif
