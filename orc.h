#ifndef __ORC_H_
#define __ORC_H_

#include "pc.h"

enum class SpriteType;

class Orc : public PC {
 public:
    SpriteType getType() const override;

    int getGold() const override;

    Orc();
    Orc(const Orc & other);
    Orc & operator=(const Orc & other);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient
    ~Orc();
};

#endif
