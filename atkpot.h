#ifndef __ATKPOT_H_
#define __ATKPOT_H_

#include "potion.h"

class PC;

class AtkPot : public Potion {
 public:
    void use(PC & user) override;
    AtkPot(const bool positive, const bool used = true);
    AtkPot & operator=(const AtkPot & other);
    ~AtkPot() {};
};

#endif
