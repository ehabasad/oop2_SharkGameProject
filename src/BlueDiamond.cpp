#include "BlueDiamond.h"

BlueDiamond::BlueDiamond(sf::Vector2f p)
	:StaticObject(p), m_animation(DataBase::instance().animationData(DataBase::BlueDiamond),Direction::Right, m_sprite)
{
	m_sprite.setPosition(p);
	m_sprite.setScale(6.f, 6.f);
}

void BlueDiamond::update(sf::Time delta)
{
	m_animation.update(delta);
}

void BlueDiamond::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}