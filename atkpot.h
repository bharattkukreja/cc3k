#ifndef __ATKPOT_H_
#define __ATKPOT_H_

#include "potion.h"

enum class SpriteType;

class PC;

class AtkPot : public Potion {
 public:
    SpriteType getType() const override;

    void use(PC & user) override; // AtkPots change their user's attack

    explicit AtkPot(const bool positive); // value is a default value and isVisible comes with them
    AtkPot(const AtkPot & other);
    AtkPot & operator=(const AtkPot & other);
    // no move ctor/assignment operator because there are no pointers to move -- it wouldn't be faster.
    ~AtkPot();
};

#endif
