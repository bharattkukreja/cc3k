#ifndef __GOLD_H_
#define __GOLD_H_

#include "item.h"

class PC;
enum class SpriteType;

class Gold : public Item {
    int value;
 public:
    SpriteType getType() const override;

    void use(PC & user) override; // put the gold in the PC's pocket!

    Gold();
    explicit Gold(const int value);
    Gold(const Gold & other);
    Gold & operator=(const Gold & other);
    // no move ctor/assignment operator because there is no heap allocated data that would make this go faster
    ~Gold();
};

#endif
