#include "Data.h"

Data::Data(int lvl, int score, int lives)
	:m_score(score), m_level(lvl), m_lives(lives)
{
	m_font.loadFromFile("font.TTF");
	m_levelTxt.setFont(m_font);
	m_scoreTxt.setFont(m_font);
	m_livesTxt.setFont(m_font);

	setUpTXT(m_scoreTxt, sf::Color::White);
	setUpTXT(m_levelTxt, sf::Color::Yellow);
	setUpTXT(m_livesTxt, sf::Color::Green);
}

void Data::updateScore(int x)
{
	m_lastScore = m_score;
	m_score = x;
}

void Data::setPos(int width, int height)
{
	m_levelTxt.setCharacterSize(1140 / 30);
	m_livesTxt.setCharacterSize(1140 / 30);
	m_scoreTxt.setCharacterSize(1140 / 30);
	m_scoreTxt.setPosition(width - WIDTH, 10);
	m_levelTxt.setPosition(width - (WIDTH / 3.0f) * 1.1f, 10);
	m_livesTxt.setPosition(width - (WIDTH / 3.0f) * 2.2f, 10);
}

void Data::updateTxt()
{
	m_levelTxt.setString("level: " + std::to_string(m_level));
	m_scoreTxt.setString("score: " + std::to_string(m_score));
	m_livesTxt.setString("life: " + std::to_string(m_lives));
}

void Data::draw(sf::RenderWindow& window)
{
	updateTxt();
	window.draw(m_levelTxt);
	window.draw(m_livesTxt);
	window.draw(m_scoreTxt);
}

void Data::setUpTXT(sf::Text& txt, sf::Color color)
{
	txt.setFillColor(color);
	txt.setOutlineThickness(3);
	txt.setOutlineColor(sf::Color::Black);
}
