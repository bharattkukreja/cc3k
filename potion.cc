#include "potion.h"
#include "spritetype.h"
using namespace std;

bool Potion::isPositive() const { return positive; }

int Potion::getValue() const { return positive ? value : -value; }


Potion::Potion(const bool positive, const int value): positive{positive}, value{value} {}

Potion::Potion(const Potion & other): positive{other.positive}, value{other.value} {}

Potion::~Potion() {}
