#include "gold.h"
#include "pc.h"
using namespace std;

void Gold::use(const PC & user) {
    user.changeGold(value);
    used = true;
}

Gold::Gold(const Gold & other): used{other.used}, value{other.value} {}

Gold & Gold::operator=(const Gold & other) {
    used = other.used;
    value = other.value;
}
