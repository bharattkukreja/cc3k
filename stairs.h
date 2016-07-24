#ifndef __STAIRS_H_
#define __STAIRS_H_

#include "stationary.h"

class Stairs : public Stationary {
 public:
    Stairs();
    ~Stairs();
}; // yay empty classes~~
// this exists so GameMap knows when to make end a floor

#endif
