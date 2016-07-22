#include "potion.h"

Potion::Potion(const bool positive, const int value, const bool visible): positive{positive}, value{value}, visible{visible} {}

Potion::Potion(const Potion & other): positive{other.positive}, value{other.value}, visible{other.visible} {}
