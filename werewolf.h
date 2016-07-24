#ifndef __WEREWOLF_H_
#define __WEREWOLF_H_

#include "npc.h"

enum class SpriteType;

class Werewolf : public NPC {
 public:
    SpriteType getType() const override;

    Werewolf();
    Werewolf(const Werewolf & other);
    Werewolf & operator=(const Werewolf & other);
    ~Werewolf();
};

#endif
