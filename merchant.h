#ifndef __MERCHANT_H_
#define __MERCHANT_H_

#include "npc.h"

enum class SpriteType;

class Merchant : public NPC {
 public:
    SpriteType getType() const override;

    Merchant();
    Merchant(const Merchant & other);
    Merchant & operator=(const Merchant & other);
    ~Merchant();

    unsigned int getHit(const unsigned int vsAtk) override; // sets all merchants to hostile
};

#endif
