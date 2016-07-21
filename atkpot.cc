#include "atkpot.h"
#include "pc.h"
using namespace std;

const int changeAtkPot = 5;

AtkPot::AtkPot(const bool positive, const bool used = true): Potion::value{changeAtkPot}, Potion::positive{positive}, Item::used{used} {}

void AtkPot::use(PC & user) {
    int effect = change;
    if (!positive) effect *= -1;
    changeAttr(user.atk, effect, 1);
}
