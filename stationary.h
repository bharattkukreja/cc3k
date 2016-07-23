#ifndef __STATIONARY_H_
#define __STATIONARY_H_

#include "sprite.h"

class Stationary : public Sprite {
 public:
    virtual ~Stationary() = 0;
}; // this class only exists to contain both treasure
// and stairs, which are stationary and pointed to by tiles

#endif
