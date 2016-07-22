#include "npc.h"
#include <cmath>
using namespace std;

int NPC::getGoldDropped() { return goldDropped; }

bool NPC::isNPC() { return true; }

bool NPC::hit(PC & target) {
    bool doesHit = rand() % 2; // randomly generates a bool to give 50% chance to miss
    if (doesHit) {
        strike(atk, target);
    }
    return doesHit;
}
