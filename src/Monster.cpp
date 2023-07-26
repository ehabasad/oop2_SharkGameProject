#include "Monster.h"
#include "DataBase.h"

constexpr auto MonsterSpeed = 60.f;

Monster::Monster(sf::Vector2f p)
    :GlobalMonster(p),m_animation(DataBase::instance().animationData(DataBase::Monster),
        Direction::Right,m_sprite) , m_radius(50)
{
    m_sprite.setPosition(p);
    m_sprite.setScale(3.f, 3.f);

    m_center.x = m_sprite.getPosition().x;
    m_center.y = (m_sprite.getPosition().y + m_radius);
}

void Monster::update(sf::Time delta)
{
    if (m_aiTime.getElapsedTime().asSeconds() >= 3)
    {
        m_aiTime.restart();
        m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Max));
        m_animation.direction(m_dir);
    }
    if (!m_collisionX)
    {
        m_sprite.move(toVector(m_dir) * delta.asSeconds() * MonsterSpeed);
        m_animation.update(delta);
    }
    else {
        //m_dir = opposite(m_dir);
        m_sprite.move(toVector(m_dir) * delta.asSeconds() * (-MonsterSpeed));
        m_animation.update(delta);
        m_collisionX = false;
    }
}

void Monster::move(sf::Time delta)
{
    static int i = 0;
  
    if (i >= 4)
    {
        static float m_angle = 0.f;
        m_angle += 0.01f;
        float x = m_center.x + cos(m_angle) * m_radius;
        float y = m_center.y + sin(m_angle) * m_radius;
        //if no collision

        i = 0;
        m_sprite.setPosition(x, y);
    }
  
    i++;
}

void Monster::draw(sf::RenderTarget& target) const
{
    target.draw(m_sprite);
}

sf::FloatRect Monster::getRect() const
{
    auto tmp = DynamicObject::m_sprite;
    tmp.move(m_step);
    return tmp.getGlobalBounds();
}
