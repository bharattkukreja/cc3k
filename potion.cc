#include "potion.h"
using namespace std;

bool Potion::getPositive() { return positive; }

int Potion::getValue() { return value; }

Potion::Potion(const bool positive, const int value): positive{positive}, value{value} {}

Potion::Potion(const Potion & other): positive{other.positive}, value{other.value} {}
