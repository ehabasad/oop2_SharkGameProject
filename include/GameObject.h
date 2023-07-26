#pragma once
#include <SFML/Graphics.hpp>
#include "DataBase.h"
#include <optional>

int const WIDTH = 1000;
int const HEIGHT = 1850;
int const OBJECTSIZE = 100;

namespace
{
	std::optional<Direction> toDirection(sf::Keyboard::Key key)
	{
		switch (key)
		{
		case sf::Keyboard::Left:
			return Direction::Left;
		case sf::Keyboard::Right:
			return Direction::Right;
		case sf::Keyboard::Up:
			return Direction::Up;
		case sf::Keyboard::Down:
			return Direction::Down;

		default:
			return Direction::Stay;
		}
		return {};
	}
}

class GameObject {
public:
	GameObject() = default;
	GameObject(sf::Vector2f p) :m_pos(p) {}
	virtual void draw(sf::RenderTarget& target) const = 0;
	virtual void update(sf::Time delta) = 0;
	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture pic);
	void setSprite() { m_sprite.setTexture(m_pic); m_sprite.setPosition(m_pos); }
	sf::Sprite getSprite() const { return m_sprite; }
	virtual sf::FloatRect getRect() const =0;
	~GameObject() = default;
protected:
	sf::Texture m_pic;
	sf::Sprite m_sprite;
	sf::Vector2f m_pos;

};