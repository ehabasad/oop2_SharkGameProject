#include "KeyObj.h"
#include "DataBase.h"

constexpr auto gobletSpeed = 200.f;

KeyObj::KeyObj()
    : m_animation(DataBase::instance().animationData(DataBase::KeyObj), Direction::Right, m_sprite)
{
    m_sprite.setScale(4.f, 4.f);
}

KeyObj::KeyObj(sf::Vector2f p)
    : StaticObject(p), m_animation(DataBase::instance().animationData(DataBase::KeyObj), Direction::Right, m_sprite)
{
    m_sprite.setPosition(p);
    m_sprite.setScale(6.f, 6.f);
}

void KeyObj::draw(sf::RenderTarget& target) const
{
    target.draw(m_sprite);
}

void KeyObj::update(sf::Time delta)
{
    if (m_aiTime.getElapsedTime().asSeconds() >= 3)
    {
        m_aiTime.restart();
        m_animation.direction(m_dir);
    }
    m_animation.update(delta);
}



