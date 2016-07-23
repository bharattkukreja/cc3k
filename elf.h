#ifndef __ELF_H_
#define __ELF_H_

#include "spritetype.h"
#include "sprite.h"
#include "character.h"
#include "pc.h"

const unsigned int humanHP = 140, humanAtk = 25, humanDef = 25;

class Elf : public PC {
 public:
    Elf();
    Elf(const Elf & other);
    Elf & operator=(const Elf & other);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient
    ~Elf() {};
};

#endif
