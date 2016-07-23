#ifndef __MERCHANT_H_
#define __MERCHANT_H_

#include "npc.h"

class Merchant : public NPC {
 public:
    Merchant();
    Merchant(const Merchant & other);
    Merchant & operator=(const Merchant & other);
    ~Merchant();

    void setHostile(const bool newHostile) override;
};

#endif
