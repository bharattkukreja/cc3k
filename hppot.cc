#include "atkpot.h"
#include "pc.h"
using namespace std;

bool HPPot::visiblePositive = HPPot::visibleNegative = false;

const unsigned int valueHPPot = 10;

bool HPPot::isVisible() const { return positive ? visiblePositive : visibleNegative; }

HPPot::HPPot(const bool positive): Potion{positive, valueHPPot} {}

HPPot::HPPot(const HPPot & other): Potion{other.positive, other.value} {}

void HPPot::use(PC & user) {
    int effect = value;
    if (!(positive || user.isElf())) { effect *= -1; }
    positive ? visiblePositive : visibleNegative = true;
    user.changeHP(effect);
}

HPPot::~HPPot() {}
