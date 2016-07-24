#ifndef __ELF_H_
#define __ELF_H_

#include "pc.h"

class Elf : public PC {
 public:
    SpriteType getType() const override;

    bool isElf() const override;

    Elf();
    Elf(const Elf & other);
    Elf & operator=(const Elf & other);
    // no move assignment operator or ctor since Human contains no pointers. copying is just as efficient
    ~Elf();
};

#endif
