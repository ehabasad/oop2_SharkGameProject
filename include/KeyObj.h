#pragma once
#include "StaticObject.h"
#include "Direction.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

class KeyObj : public StaticObject {
public:
	KeyObj();
	KeyObj(sf::Vector2f p);
	virtual void draw(sf::RenderTarget& target) const override;
	void update(sf::Time delta) override;
	~KeyObj() = default;
private:
	Animation m_animation;
	Direction m_dir = Direction::Right;
	//sf::Sprite m_sprite;
	sf::Clock m_aiTime;
};