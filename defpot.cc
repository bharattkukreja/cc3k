#include "defpot.h"
#include "pc.h"
#include "spritetype.h"
using namespace std;

const unsigned int valueDefPot = 5;

DefPot::DefPot(const bool positive): Potion{positive, valueDefPot} {}

DefPot::DefPot(const DefPot & other): Potion{other.positive, other.value} {}

void DefPot::use(PC & user) {
    int effect = value;
    if (!(positive || user.isElf())) { effect *= -1; }
    user.changeDef(effect);
}

DefPot::~DefPot() {};


SpriteType DefPot::getType() const { return SpriteType::DefPot; }
