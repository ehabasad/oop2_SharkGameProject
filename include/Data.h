#pragma once
#include "PlayerObj.h"
#include <SFML/Graphics.hpp>

class Data {
public:
	Data() = default;
	Data(int lvl, int score, int lives);
	void updateScore(int x);
	int getScore() const { return m_score; }
	int getLastScore()const { return m_lastScore; }
	void updateLives(int x) { m_lives = x; }
	int getLives() const { return m_lives; }
	void updateLvl(int x) { m_level = x; }
	int getLvl()const { return m_level; }
	void setPos(int width, int height);
	void updateTxt();
	void draw(sf::RenderWindow& window);
	void setUpTXT(sf::Text& txt, sf::Color color);
	~Data() = default;

private:
	int m_level,
		m_score,
		m_lastScore,
		m_lives;

	sf::Font m_font;

	sf::Text m_levelTxt,
			m_scoreTxt,
			m_livesTxt;
};