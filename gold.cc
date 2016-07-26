#include "gold.h"
#include "pc.h"
#include "spritetype.h"
using namespace std;

void Gold::use(PC & user) { user.changeGold(value); }


const int defaultValue = 1;

Gold::Gold(): value{defaultValue} {}

Gold::Gold(const int value): value{value} {}

Gold::Gold(const Gold & other): value{other.value} {}

Gold & Gold::operator=(const Gold & other) {
    value = other.value;
    return *this;
}

Gold::~Gold() {}


SpriteType Gold::getType() const { return SpriteType::Gold; }
