#ifndef __GOLD_H_
#define __GOLD_H_

#include "sprite.h"
#include "stationary.h"
#include "item.h"
#include "pc.h"
#include "spritetype.h"

int defaultValue = 1;

class Gold : public Item {
    int value;
 public:
    void use(PC & user) override;
    explicit Gold(int amount = defaultValue): used{false}, value{amount} {}
    Gold(const Gold & other);
    Gold & operator=(const Gold & other);
    ~Gold() {};
};

#endif
