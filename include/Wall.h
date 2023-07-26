#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "Direction.h"


class Wall : public StaticObject {
public:
	Wall() = default;
	Wall(sf::Vector2f p);
	void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target) const override;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	sf::Clock m_aiTime;
};
