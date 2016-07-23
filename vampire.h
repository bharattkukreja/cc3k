#ifndef __VAMPIRE_H_
#define __VAMPIRE_H_
#define __DR_ACULA_

#include "npc.h"

class Vampire : public NPC {
 public:
    Vampire();
    Vampire(const Vampire & other);
    Vampire & operator=(const Vampire & other);
    ~Vampire();
};

#endif
