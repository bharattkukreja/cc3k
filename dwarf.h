#ifndef __DWARF_H_
#define __DWARF_H_

#include "pc.h"

enum class SpriteType;

class Dwarf : public PC {
 public:
    SpriteType getType() const override;

    int getGold() const override;

    Dwarf();
    Dwarf(const Dwarf & other);
    Dwarf & operator=(const Dwarf & other);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient

    ~Dwarf();
};

#endif
