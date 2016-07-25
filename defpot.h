#ifndef __DEFPOT_H_
#define __DEFPOT_H_

#include "potion.h"

enum class SpriteType;
class PC;

class DefPot : public Potion {
    static bool visiblePositive, visibleNegative;
 public:
    SpriteType getType() const override;

    void use(PC & user) override; // DefPots change their user's attack
    bool isVisible() const override; // gets visible based on whether the potion is positive or negative

    explicit DefPot(const bool positive); // value is a default value and isVisible comes with them
    DefPot(const DefPot & other);
    DefPot & operator=(const DefPot & other);
    // no move ctor/assignment operator because there are no pointers to move -- it wouldn't be faster.
    ~DefPot();
};

#endif
