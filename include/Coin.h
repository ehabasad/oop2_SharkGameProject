#pragma once
#include "StaticObject.h"
#include"Animation.h"

class Coin : public StaticObject {
public:
	Coin()=default;
	virtual void draw(sf::RenderTarget& target) const override;
	void update(sf::Time delta) override;
	Coin(sf::Vector2f p);
	~Coin() = default;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	sf::Clock m_aiTime;
};