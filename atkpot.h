#ifndef __ATKPOT_H_
#define __ATKPOT_H_

#include "sprite.h"
#include "stationary.h"
#include "item.h"
#include "potion.h"
#include "spritetype.h"

const int changeAtkPot = 5;

class AtkPotion : public Potion {
 public:
    void use(PC * user) override;
    AtkPot(const bool positive, const bool used = true): value{changeAtkPot}, positive{positive}, used{used} {}
    AtkPot & operator=(const AtkPot & other);
    ~AtkPot() {};
};

#endif
