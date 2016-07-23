#include "defpot.h"
#include "pc.h"
using namespace std;

bool DefPot::visiblePositive = DefPot::visibleNegative = false;

const unsigned int valueDefPot = 5;

bool DefPot::isVisible() const { return positive ? visiblePositive : visibleNegative; }

DefPot::DefPot(const bool positive): Potion{positive, valueDefPot} {}

DefPot::DefPot(const DefPot & other): Potion{other.positive, other.value} {}

void DefPot::use(PC & user) {
    int effect = value;
    if (!positive) { effect *= -1; }
    positive ? visiblePositive : visibleNegative = true;
    user.changeDef(effect);
}