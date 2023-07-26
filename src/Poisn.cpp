#include "Poisn.h"
#include <optional>
constexpr auto speed = 35.f;

Poisn::Poisn(sf::Vector2f p)
	:StaticObject(p), m_animation(DataBase::instance().animationData(DataBase::Poisn),
		Direction::Right, m_sprite)
{
	m_sprite.setPosition(p);
	m_sprite.setScale(6.f, 6.f);
}

void Poisn::update(sf::Time delta)
{
    m_animation.update(delta);
}

void Poisn::draw(sf::RenderTarget& target) const
{
	target.draw(StaticObject::m_sprite);
}
