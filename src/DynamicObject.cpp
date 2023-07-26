#include "DynamicObject.h"

DynamicObject::DynamicObject()
	:m_isKilled(false)
{
}

DynamicObject::DynamicObject(sf::Vector2f p)
	: GameObject(p)
{
	m_isKilled = false;
}

bool DynamicObject::killed() const
{
	if (m_isKilled)
		return true;
	return false;
}
