#ifndef __ITEM_H_
#define __ITEM_H_

#include "sprite.h"
#include "stationary.h"
#include "pc.h"
#include "spritetype.h"

class Item : public Stationary {
 public:
    bool used;
    virtual void use(PC & user) = 0;
};

#endif
