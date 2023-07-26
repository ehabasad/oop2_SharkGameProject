#pragma once
#include "StaticObject.h"
#include "Animation.h"

class Door :public StaticObject {
public:
	Door() = default;
	Door(sf::Vector2f p);
	virtual void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target) const override;
	~Door() = default;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	sf::Clock m_aiTime;

};
