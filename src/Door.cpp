#include "Door.h"

Door::Door(sf::Vector2f p)
	:StaticObject(p), m_animation(DataBase::instance().animationData(DataBase::Door),
		Direction::Right, m_sprite)
{
	m_sprite.setPosition(p);
	m_sprite.setScale(2.5f, 2.5f);
}

void Door::update(sf::Time delta)
{
	m_animation.update(delta);
}

void Door::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}