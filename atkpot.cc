#include "atkpot.h"
#include "pc.h"
using namespace std;

extern const int valueAtkPot;

extern bool visiblePosAtkPot;

extern bool visibleNegAtkPot;

AtkPot::AtkPot(const bool positive): Potion::value{valueAtkPot}, Potion::positive{positive} {
    Potion::visible = Potion::positive ? visiblePosAtkPot : visibleNegAtkPot;
}

void AtkPot::use(PC & user) {
    int effect = value;
    if (!Potion::positive) effect *= -1;
    changeAttr(user.atk, effect, 1);
}
