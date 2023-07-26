#include "Coin.h"

Coin::Coin(sf::Vector2f p)
	:StaticObject(p), m_animation(DataBase::instance().animationData(DataBase::Coin),Direction::Right, m_sprite)
{
	m_sprite.setPosition(p);
	m_sprite.setScale(6.f, 6.f);
}

void Coin::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}

void Coin::update(sf::Time delta)
{
	m_animation.update(delta);
}
