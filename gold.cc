#include "gold.h"
#include "pc.h"
#include "spritetype.h"
using namespace std;

const unsigned int defaultValue = 1;

void Gold::use(PC & user) { user.changeGold(value); }

Gold::Gold(const unsigned int value = defaultValue): value{value} {}

Gold::Gold(const Gold & other): value{other.value} {}

Gold & Gold::operator=(const Gold & other) {
    value = other.value;
    return *this;
}

Gold::~Gold() {}


SpriteType Gold::getType() const { return SpriteType::Gold; }
