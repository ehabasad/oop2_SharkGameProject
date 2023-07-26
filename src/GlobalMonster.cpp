#include "GlobalMonster.h"
#include "DynamicObject.h"

GlobalMonster::GlobalMonster(sf::Vector2f p)
	:DynamicObject(p)
{
	setKill(false);
}
