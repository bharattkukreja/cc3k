#ifndef __TROLL_H_
#define __TROLL_H_

#include "npc.h"

class Troll : public NPC {
 public:
    Troll();
    Troll(const Troll & other);
    Troll & operator=(const Troll & other);
    ~Troll();
};

#endif
