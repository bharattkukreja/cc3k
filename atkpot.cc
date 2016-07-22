#include "atkpot.h"
#include "pc.h"
using namespace std;

extern const int valueAtkPot;

extern bool visiblePosAtkPot;

extern bool visibleNegAtkPot;

AtkPot::AtkPot(const bool positive): Potion::value{valueAtkPot}, Potion::positive{positive} {
    Potion::visible = positive ? visiblePosAtkPot : visibleNegAtkPot;
}

void AtkPot::use(PC & user) {
    int effect = change;
    if (!positive) effect *= -1;
    changeAttr(user.atk, effect, 1);
}
