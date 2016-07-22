#include "atkpot.h"
#include "pc.h"
using namespace std;

extern const int valueAtkPot;

extern bool visiblePosAtkPot;

extern bool visibleNegAtkPot;

AtkPot::AtkPot(const bool positive): Potion{positive, valueAtkPot, positive ? visiblePosAtkPot : visibleNegAtkPot} {}

AtkPot::AtkPot(const AtkPot & other): Potion{other.positive, other.value, other.visible} {}

void AtkPot::use(PC & user) {
    int effect = value;
    if (!Potion::positive) effect *= -1;
    user.changeAtk(effect);
}
