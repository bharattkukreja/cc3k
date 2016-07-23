#ifndef __HPPOT_H_
#define __HPPOT_H_

#include "potion.h"

class PC;

class HPPot : public Potion {
    static bool visiblePositive, visibleNegative;
 public:
    void use(PC & user) override; // AtkPots change their user's attack
    bool isVisible() const override; // gets visible based on whether the potion is positive or negative
    explicit HPPot(const bool positive); // value is a default value and isVisible comes with them
    HPPot(const HPPot & other);
    HPPot & operator=(const HPPot & other);
    // no move ctor/assignment operator because there are no pointers to move -- it wouldn't be faster.
    ~HPPot();
};

#endif
