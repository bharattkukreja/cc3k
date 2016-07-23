include "npc.h"
using namespace std;

bool NPC::isHostile() { return hostile; }

void NPC::setHostile(const bool newHostile) { hostile = newHostile; }

int NPC::getGoldDropped() { return goldDropped; }

bool NPC::isNPC() const override { return true; }

bool NPC::hit(PC & target) {
    bool doesHit = rand() % 2; // randomly generates a bool to give 50% chance to miss
    if (doesHit) {
        strike(atk, target);
    }
    return doesHit;
}

NPC::NPC(const unsigned int hp, const unsigned int atk, const unsigned int def, const unsigned int goldDropped, const bool hostile): Character{hp, atk, def}, hostile{hostile}, goldDropped{goldDropped} {}

NPC::NPC(const NPC & other): Character{other}, hostile{other.hostile}, goldDropped{other.goldDropped} {}

NPC::NPC(): {}
