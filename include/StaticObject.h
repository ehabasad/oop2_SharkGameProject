#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class StaticObject :public GameObject {
public:
    StaticObject();
    StaticObject(sf::Vector2f p);
    virtual void update(sf::Time delta) = 0;
    virtual void draw(sf::RenderTarget& target) const = 0;
    virtual sf::FloatRect getRect() const override;
    ~StaticObject() = default;
private:
    Direction m_dir = Direction::Right;
};