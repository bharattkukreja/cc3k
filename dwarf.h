#ifndef __DWARF_H_
#define __DWARF_H_

#include "pc.h"

class Dwarf : public PC {
 public:
    int getGold() const override;

    Dwarf();
    Dwarf(const Dwarf & other);
    Dwarf & operator=(const Dwarf & other);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient

    ~Dwarf();
};

#endif
