#ifndef __POTION_H_
#define __POTION_H_

#include "item.h"

class Potion : public Item {
 public:
    bool isVisible, positive;
    int value;
};

#endif
