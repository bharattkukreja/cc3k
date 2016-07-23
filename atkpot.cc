#include "atkpot.h"
#include "pc.h"
using namespace std;

bool AtkPot::visiblePositive = AtkPot::visibleNegative = false;

const unsigned int valueAtkPot = 5;

bool AtkPot::isVisible() const { return positive ? visiblePositive : visibleNegative; }

AtkPot::AtkPot(const bool positive): Potion{positive, valueAtkPot} {}

AtkPot::AtkPot(const AtkPot & other): Potion{other.positive, other.value} {}

void AtkPot::use(PC & user) {
    int effect = value;
    if (!(positive || user.isElf())) { effect *= -1; }
    positive ? visiblePositive : visibleNegative = true;
    user.changeAtk(effect);
}

AtkPot::~AtkPot() {};
