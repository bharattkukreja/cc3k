#ifndef __SPRITE_H_
#define __SPRITE_H_

#include "spritetype.h"

class Sprite { // abstract class for Cells in the Map to point to
 public:
    virtual SpriteType & getType(); // enumerates subclasses for the Map's benefit

    virtual bool isPC() const; // virtual because PC overrides it to return true
    virtual bool isNPC() const; // ibid but with NPC
    virtual bool isItem() const; // ibid but with Item
    virtual bool isElf() const; // for elves so potions don't negatively affect their stats

    virtual ~Sprite() {}
};

#endif
