#ifndef __WEREWOLF_H_
#define __WEREWOLF_H_

#include "npc.h"

class Werewolf : public NPC {
 public:
    Werewolf();
    Werewolf(const Werewolf & other);
    Werewolf & operator=(const Werewolf & other);
    ~Werewolf();
};

#endif
