#ifndef __HPPOT_H_
#define __HPPOT_H_

#include "potion.h"

enum class SpriteType;
class PC;

class HPPot : public Potion {
 public:
    SpriteType getType() const override;

    void use(PC & user) override; // AtkPots change their user's attack

    explicit HPPot(const bool positive); // value is a default value and isVisible comes with them
    HPPot(const HPPot & other);
    HPPot & operator=(const HPPot & other);
    // no move ctor/assignment operator because there are no pointers to move -- it wouldn't be faster.
    ~HPPot();
};

#endif
