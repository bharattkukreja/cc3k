#ifndef __POTION_H_
#define __POTION_H_

#include "item.h"

enum class SpriteType;

class Potion : public Item {
 protected:
    bool positive;
    int value;
 public:
    SpriteType getType() const override;

    virtual bool isVisible() const = 0; // requires static variables from subclasses
    bool isPositive() const;
    int getValue() const;
    // don't need setters for positive or value because they don't change after the potion is ctor'd
    
    Potion(const bool positive, const int value);
    Potion(const Potion & other);
    virtual ~Potion() = 0;
};

#endif
