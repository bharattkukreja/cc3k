#include "goblin.h"
#include "npc.h"
#include "character.h"
using namespace std;

Goblin & Goblin::operator=(const Goblin & other) {
    hp = other.hp;
    goldDropped = other.goldDropped;
    hostile = other.hostile;
    atk = other.atk;
    def = other.def;
}
