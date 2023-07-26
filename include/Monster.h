#pragma once
#include "Direction.h"
#include "Animation.h"
#include "DynamicObject.h"
#include "GlobalMonster.h"
#include <SFML/Graphics.hpp>


class Monster : public GlobalMonster {
public:
    Monster() = default;
    Monster(sf::Vector2f p);
    virtual void update(sf::Time delta) override;
    virtual void move(sf::Time delta) override;
    virtual void draw(sf::RenderTarget& target) const override;
    virtual sf::FloatRect getRect() const override;
    ~Monster() = default;
private:
    Direction m_dir = Direction::Right;
    Animation m_animation;
    sf::Clock m_aiTime;
    const int m_radius;
    sf::Vector2f m_center;
};