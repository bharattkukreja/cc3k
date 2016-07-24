#ifndef __HUMAN_H_
#define __HUMAN_H_

#include "pc.h"

enum class SpriteType;

class Human : public PC {
 public:
    SpriteType getType() const override;

    int score() const override;

    Human();
    Human(const Human & other);
    Human & operator=(const Human & other);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient
    ~Human();
};

#endif
