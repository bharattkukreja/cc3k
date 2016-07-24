#ifndef __POTION_H_
#define __POTION_H_

#include "item.h"

class Potion : public Item {
 protected:
    bool visible, positive;
    int value;
 public:
    bool getVisible() const;
    bool getPositive() const;
    int getValue() const;
    void setVisible(bool nowVisible);
    // don't need setters for positive or value because they don't change after the potion is ctor'd
    Potion(const bool positive, const int value, const bool visible);
    Potion(const Potion & other);
};

#endif
