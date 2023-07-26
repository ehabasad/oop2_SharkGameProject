#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "Direction.h"
#include <optional>

class Water : public StaticObject {
public:
	Water() = default;
	virtual void draw(sf::RenderTarget& target) const override;
	void update(sf::Time delta) override;
	Water(sf::Vector2f p);
	~Water() = default;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	sf::Clock m_aiTime;
};
