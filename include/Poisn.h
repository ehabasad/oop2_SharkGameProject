#pragma once
#include "StaticObject.h"
#include "Animation.h"
#include "Direction.h"
#include <optional>

class Poisn :public StaticObject{
public:
	Poisn() = default ;
	Poisn(sf::Vector2f p) ;
	void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target) const override;
	~Poisn() = default;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	sf::Clock m_aiTime;

};