#ifndef __ITEM_H_
#define __ITEM_H_

#include "sprite.h"
#include "stationary.h"
#include "pc.h"
#include "spritetype.h"

class Item : public Stationary {
 public:
    bool isItem() const override;

    virtual void use(PC & user) = 0; // items (gold & potions & maybe other) are used differently

    Item();
    virtual ~Item() = 0;
};

#endif
