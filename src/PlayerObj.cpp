#include "PlayerObj.h"
#include "DataBase.h"
#include <optional>


PlayerObj::PlayerObj(sf::Vector2f p)
	:DynamicObject(p),
	m_animation(DataBase::instance().animationData(DataBase::PlayerObj), Direction::Up, m_sprite)
	, m_lives(3), m_iswin(false), m_gobletTaken(false) ,m_score(0) , m_firstPos(p) ,m_canJump(true)
{
	m_speed = 200.f;
	m_sprite.setPosition(p);
	m_sprite.setScale(1.f, 1.f);
}

void PlayerObj::update(sf::Time delta)
{
	if (m_dir == Direction::Stay)
	{
		return;
	}

	m_animation.update(delta);
	this->move(delta);
}

void PlayerObj::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);
}

void PlayerObj::direction(sf::Keyboard::Key key)
{
	if (auto dir = toDirection(key))
	{
		m_dir = *dir;
		m_animation.direction(*dir);
	}
	
}
sf::FloatRect PlayerObj::getRect() const
{
	auto tmp = m_sprite;
	tmp.move(m_step);
	return tmp.getGlobalBounds();
}

void PlayerObj::decreaseLive()
{
	m_lives--;
	if (m_lives < 0)
		setKill(true);
	m_sprite.setPosition(m_firstPos);
}

void PlayerObj::move(sf::Time delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
		if (m_collisionX || m_collisionY)
			m_sprite.move(m_step);
		else
		{
			m_step = toVector(m_dir);
			auto stp = m_step * m_speed * delta.asSeconds();
			m_sprite.move(stp);
		}
		
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_collisionY)
			m_sprite.move(m_step);
		m_step = toVector(m_dir);
		auto stp = m_step * m_speed *(float)10* delta.asSeconds();
		m_sprite.move(stp);
	}
	if (m_dir == Direction::Stay)
	{
		return;
	}
}

void PlayerObj::moveDown(float dis)
{
	m_dir = Direction::Down;
	m_step = toVector(m_dir);
	auto stp = m_step * dis;
	m_sprite.move(stp);
	m_onAir = false;
}

void PlayerObj::winMove(sf::Time delta , Direction d)
{
	update(delta);
	m_step = toVector(m_dir);
	auto stp = m_step * m_speed * delta.asSeconds();
	m_sprite.move(stp);
}

int PlayerObj::getLive() const
{
	return m_lives;
}
