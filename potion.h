#ifndef __POTION_H_
#define __POTION_H_

#include "sprite.h"
#include "stationary.h"
#include "item.h"
#include "pc.h"
#include "spritetype.h"

class Potion : public Item {
 public:
    bool isVisible, isPositive;
    int change;
};

#endif
