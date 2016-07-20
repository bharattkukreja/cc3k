#include "atkpot.h"
#include "pc.h"
using namespace std;

void use(PC & user) {
    int effect = change;
    if (!positive) effect *= -1;
    changeAttr(user.atk, effect, 1);
}
