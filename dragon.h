#ifndef __DRAGON_H_
#define __DRAGON_H_

#include "npc.h"

class Dragon : public NPC {
 public:
    Dragon();
    Dragon(const Dragon & other);
    Dragon & operator=(const Dragon & other);
    ~Dragon();
};

#endif
