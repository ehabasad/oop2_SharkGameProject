#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "Direction.h"

class BlueDiamond : public StaticObject {
public:
	BlueDiamond()=default;
	BlueDiamond(sf::Vector2f p);
	virtual void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target) const override;
	~BlueDiamond() = default;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	sf::Clock m_aiTime;
};