#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "Direction.h"
#include <SFML/Graphics.hpp>

class Gift : public StaticObject {
public:
	Gift() = default;
	Gift(sf::Vector2f p);
	virtual void draw(sf::RenderTarget& target) const override;
	void update(sf::Time delta) override;
	~Gift() = default;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	sf::Clock m_aiTime;
};