#ifndef __SPRITE_H_
#define __SPRITE_H_

#include "spritetype.h"

class Sprite {
 public:
    virtual SpriteType & getType();
    virtual bool isPC();
    virtual bool isNPC();
    virtual ~Sprite() = 0;
};

#endif
