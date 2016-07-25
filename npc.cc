#include <cstdlib>
#include <ctime>
#include <utility>
#include "npc.h"
#include "pc.h"
using namespace std;

bool NPC::isHostile() const { return hostile; }

void NPC::setHostile(const bool newHostile) { hostile = newHostile; }


void NPC::setGoldDropped(const unsigned int gdNew) { goldDropped = gdNew; }

unsigned int NPC::getGoldDropped() const { return goldDropped; }


bool NPC::isNPC() const { return true; }

pair<bool,int> NPC::hit(PC & target) {
    srand(time(NULL));
    bool doesHit = rand() % 2; // randomly generates a bool to give 50% chance to miss
    int damage = 0;
    if (doesHit) {
        damage = target.getHit(atk);
    }
    pair<bool, int> info = make_pair(doesHit, damage);
    return info;
}


NPC::NPC(const unsigned int hp, const unsigned int atk, const unsigned int def, const unsigned int goldDropped, const bool hostile): Character{hp, atk, def}, goldDropped{goldDropped}, hostile{hostile} {}

NPC::NPC(const NPC & other): Character{other}, goldDropped{other.goldDropped}, hostile{other.hostile} {}

NPC::~NPC() {}
