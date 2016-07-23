#ifndef __PHOENIX_H_
#define __PHOENIX_H_

#include "npc.h"

class Phoenix : public NPC {
 public:
    Phoenix();
    Phoenix(const Phoenix & other);
    Phoenix & operator=(const Phoenix & other);
    ~Phoenix();
};

#endif
