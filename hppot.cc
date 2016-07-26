#include "spritetype.h"
#include "hppot.h"
#include "pc.h"
using namespace std;

const int valueHPPot = 10;


HPPot::HPPot(const bool positive): Potion{positive, valueHPPot} {}

HPPot::HPPot(const HPPot & other): Potion{other} {}

void HPPot::use(PC & user) {
    int effect = value;
    if (!(positive || user.isElf())) { effect *= -1; }
    user.changeHP(effect);
}

HPPot::~HPPot() {}


SpriteType HPPot::getType() const { return SpriteType::HPPot; }
