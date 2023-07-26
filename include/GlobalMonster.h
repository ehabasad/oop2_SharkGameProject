#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

class GlobalMonster : public DynamicObject {
public:
	GlobalMonster() = default;
	GlobalMonster(sf::Vector2f p);
	virtual void update(sf::Time delta) = 0;
	virtual void move(sf::Time delta) = 0;
	virtual void draw(sf::RenderTarget& target) const = 0;
	virtual sf::FloatRect getRect() const = 0;
	~GlobalMonster() = default;
};