#include "StaticObject.h"

StaticObject::StaticObject()
	:GameObject()
{
}

StaticObject::StaticObject(sf::Vector2f p)
	:GameObject(p)
{
	m_sprite.setScale(1.8f, 1.8f);
}

sf::FloatRect StaticObject::getRect() const
{
	return m_sprite.getGlobalBounds();
}
