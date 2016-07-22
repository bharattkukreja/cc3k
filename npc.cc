#include "npc.h"
#include <cmath>
#include "random.h"
using namespace std;

int NPC::getGoldDropped() { return goldDropped; }

bool NPC::isNPC() { return true; }

bool NPC::hit(PC & target) {
    bool doesHit = random(0,1); // randomly generates a bool to give 50% chance to miss
    if (doesHit) {
        strike(atk, target);
    }
    return doesHit;
}
