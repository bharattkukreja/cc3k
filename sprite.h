#ifndef __SPRITE_H_
#define __SPRITE_H_

#include "spritetype.h"

class Sprite { // abstract class for Cells in the Map to point to
 public:
    virtual SpriteType & getType(); // enumerates subclasses for the Map's benefit
    virtual bool isPC(); // virtual because PC overrides it to return true
    virtual bool isNPC(); // ibid but with NPC
    virtual ~Sprite() = 0;
};

#endif
