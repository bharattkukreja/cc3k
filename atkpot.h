#ifndef __ATKPOT_H_
#define __ATKPOT_H_

#include "potion.h"

class PC;

const int valueAtkPot = 5;
bool visiblePosAtkPot = false;
bool visibleNegAtkPot = false;

class AtkPot : public Potion {
 public:
    void use(PC & user) override; // AtkPots change their user's attack
    explicit AtkPot(const bool positive); // value is a default value and isVisible comes with them
    AtkPot(const AtkPot & other): visible{other.getVisible()}, positive{other.getPositive()}, value{other.getValue()} {}
    AtkPot & operator=(const AtkPot & other);
    ~AtkPot() {};
};

#endif
