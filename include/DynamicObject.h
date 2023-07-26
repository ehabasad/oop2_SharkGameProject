#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include <map>
#include "GameObject.h"
#include "Animation.h"
#include "Direction.h"


class DynamicObject : public GameObject
{
public:
	DynamicObject();
	DynamicObject(sf::Vector2f p);
	virtual void move(sf::Time delta) = 0;
	virtual void draw(sf::RenderTarget& target) const = 0;
	virtual void update(sf::Time delta) = 0;
	void setXStep(float n) { m_step.x = n; }
	void setYStep(float n) { m_step.y = n; }
	sf::Vector2f getStep()const {return m_step; }
	bool killed() const;
	void setKill(const bool& kill) { m_isKilled = kill;}
	float getSpeed() const { return m_speed; }
	bool getCollisionX() const { return m_collisionX; }
	bool getCollisionY() const { return m_collisionY; }
	void setCollisionX(bool b) { m_collisionX = b; }
	void setCollisionY(bool b) { m_collisionY = b; }
	virtual sf::FloatRect getRect() const = 0;
	~DynamicObject() = default;
protected:
	sf::Vector2f m_step;
	bool m_isKilled;
	float m_speed = 0.7f;
	Direction m_dir = Direction::Right;
	sf::Clock m_timer;
	sf::Time m_moveTimer = sf::seconds(0.2f);
	bool m_collisionX = false,
		m_collisionY = false;
};

