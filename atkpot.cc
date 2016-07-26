#include "atkpot.h"
#include "pc.h"
#include "spritetype.h"
using namespace std;

const unsigned int valueAtkPot = 5;


AtkPot::AtkPot(const bool positive): Potion{positive, valueAtkPot} {}

AtkPot::AtkPot(const AtkPot & other): Potion{other} {}

void AtkPot::use(PC & user) {
    int effect = value;
    if (!(positive || user.isElf())) { effect *= -1; }
    user.changeAtk(effect);
}

AtkPot::~AtkPot() {};

SpriteType AtkPot::getType() const { return SpriteType::AtkPot; }
