#include "Wall.h"

Wall::Wall(sf::Vector2f p)
	:StaticObject(p), m_animation(DataBase::instance().animationData(DataBase::Wall),
		Direction::Right, m_sprite)
{
	m_sprite.setPosition(p);
	m_sprite.setScale(5.f, 5.f);
}

void Wall::update(sf::Time delta)
{
	m_animation.update(delta);
}

void Wall::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}
