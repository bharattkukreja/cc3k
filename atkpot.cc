#include "atkpot.h"
#include "pc.h"
using namespace std;

static visiblePositive = false;
static visibleNegative = false;

bool AtkPot::getVisible() { return positive ? visiblePositive : visibleNegative; }

AtkPot::AtkPot(const bool positive): Potion{positive, valueAtkPot, positive ? visiblePosAtkPot : visibleNegAtkPot} {}

AtkPot::AtkPot(const AtkPot & other): Potion{other.positive, other.value, other.visible} {}

void AtkPot::use(PC & user) {
    int effect = value;
    if (!Potion::positive) {
        effect *= -1;
	visibleNegative = true;
    } else {
        visiblePositive = true;
    }
    user.changeAtk(effect);
}
