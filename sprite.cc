#include "sprite.h"
using namespace std;

bool Sprite::isPC() const { return getType() == SpriteType::Human ||
				   getType() == SpriteType::Elf ||
				   getType() == SpriteType::Orc ||
				   getType() == SpriteType:: Dwarf; }

bool Sprite::isNPC() const { return getType() == SpriteType::Vampire ||
                                    getType() == SpriteType::Werewolf ||
                                    getType() == SpriteType::Merchant ||
                                    getType() == SpriteType::Dragon ||
				    getType() == SpriteType::Troll ||
                                    getType() == SpriteType::Goblin ||
                                    getType() == SpriteType::Phoenix; }

bool Sprite::isItem() const { return getType() == SpriteType::Potion ||
				     getType() == SpriteType::Gold; }

bool Sprite::isElf() const { return getType() == SpriteType::Elf; }


Sprite::~Sprite() {}
