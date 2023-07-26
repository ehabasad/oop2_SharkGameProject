#include "Gift.h"

Gift::Gift(sf::Vector2f p)
	:StaticObject(p) , m_animation(DataBase::instance().animationData(DataBase::Gift),Direction::Right, m_sprite)
{
	m_sprite.setPosition(p);
	m_sprite.setScale(6.f, 6.f);
}

void Gift::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}

void Gift::update(sf::Time delta)
{
	m_animation.update(delta);
}