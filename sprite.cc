#include "sprite.h"
using namespace std;

virtual bool Sprite::isPC() const { return false; }

virtual bool Sprite::isNPC() const { return false; }

virtual bool Sprite::isItem() const { return false; }
