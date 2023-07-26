#pragma once
#include "DynamicObject.h"
#include "Animation.h"
#include <map>

class PlayerObj :public DynamicObject {
public:
	PlayerObj() = default;
	PlayerObj(sf::Vector2f p);
	virtual void move(sf::Time delta) override;
	void moveDown(float dis);
	void winMove(sf::Time delta , Direction d);
	int getLive() const;
	void setOnAir(bool b) { m_onAir = b; }
	bool isOnAr() const { return m_onAir; }
	virtual void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget& target) const override ;
	void direction(sf::Keyboard::Key key);
	virtual sf::FloatRect getRect() const override;
	void addScore(int s) { m_score += s; }
	void setWon(bool b) { m_iswin = b; }
	bool isWin() const { return m_iswin; }
	bool isGobletTaken() { return m_gobletTaken; }
	void setGobletTaken(bool b) { m_gobletTaken = b; }
	int getScore() const { return m_score; }
	bool isOnAir() const { return m_onAir; }
	void decreaseLive();
	~PlayerObj()= default;
private:
	int m_lives;
	sf::Vector2f m_firstPos;
	int m_score;
	Animation m_animation;
	bool m_iswin;
	bool m_onAir = false;
	bool m_canJump;
	bool m_gobletTaken;
	
};