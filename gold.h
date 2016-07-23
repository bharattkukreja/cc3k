#ifndef __GOLD_H_
#define __GOLD_H_

#include "sprite.h"
#include "stationary.h"
#include "item.h"
#include "pc.h"
#include "spritetype.h"

class Gold : public Item {
    unsigned int value;
 public:
    void use(PC & user) override; // put the gold in the PC's pocket!
    explicit Gold(const unsigned int value);
    Gold(const Gold & other);
    Gold & operator=(const Gold & other);
    // no move ctor/assignment operator because there is no heap allocated data that would make this go faster
    ~Gold();
};

#endif
