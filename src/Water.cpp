#include "Water.h"

Water::Water(sf::Vector2f p)
	:StaticObject(p), m_animation(DataBase::instance().animationData(DataBase::Water),
		Direction::Right, m_sprite)
{
	m_sprite.setPosition(p);
	m_sprite.setScale(6.f, 6.f);
}

void Water::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}

void Water::update(sf::Time delta)
{
	m_animation.update(delta);
}
