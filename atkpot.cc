#include "atkpot.h"
#include "pc.h"
using namespace std;

static bool visiblePositive = false;
static bool visibleNegative = false;

bool AtkPot::isVisible() const { return positive ? visiblePositive : visibleNegative; }

AtkPot::AtkPot(const bool positive): Potion{positive, valueAtkPot} {}

AtkPot::AtkPot(const AtkPot & other): Potion{other.positive, other.value} {}

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
