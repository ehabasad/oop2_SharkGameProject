#include "Menu.h"
#include <Windows.h>

Menu::Menu()
{
	getButton();
	getWinLosePic();
	getText();
	helpPic();
}

void Menu::getText()
{
	/*m_font.loadFromFile("arial.ttf");
	text.setFont(m_font);
	text.setCharacterSize(30);
	text.setLetterSpacing(2);
	text.setPosition(40.f, 850.f);
	text.setFillColor(sf::Color::Yellow);
	text.setString("Ehab & Lamaah :) ");*/
}

void Menu::helpPic()
{
	/*m_helpT.loadFromFile("help1.png");
	m_helpT.setSmooth(true);
	m_helpPic.setTexture(&m_helpT);*/
}
void Menu::getWinLosePic()
{
	/*m_lose.loadFromFile("cry.jpeg");
	m_lose.setSmooth(true);
	m_losePic.setTexture(&m_lose);

	m_win.loadFromFile("wink.png");
	m_win.setSmooth(true);
	m_winPic.setTexture(&m_win);*/

	m_logo.loadFromFile("back.png");
	m_logo.setSmooth(true);
	m_logoPic.setTexture(&m_logo);
}

void Menu::getButton()
{
	m_startGame.loadFromFile("start.png");
	m_startGame.setSmooth(true);
	m_startIcon.setTexture(&m_startGame);
	m_startIcon.setOutlineColor(sf::Color::White);
	m_startIcon.setOutlineThickness(4);

	m_quit.loadFromFile("quit.png");
	m_quit.setSmooth(true);
	m_quitIcon.setTexture(&m_quit);
	m_quitIcon.setOutlineColor(sf::Color::White);
	m_quitIcon.setOutlineThickness(4);

	//m_help.loadFromFile("help.png");
	//m_help.setSmooth(true);
	//m_helpIcon.setTexture(&m_help);
	//m_helpIcon.setOutlineColor(sf::Color::White);
	//m_helpIcon.setOutlineThickness(4);


}

void Menu::drawOptions(sf::RenderWindow& window)
{
	m_startIcon.setSize(sf::Vector2f(200, 80));
	m_startIcon.setPosition(220.f, 400.f);
	window.draw(m_startIcon);

	m_quitIcon.setSize(sf::Vector2f(200, 80));
	m_quitIcon.setPosition(780.f, 400.f);
	window.draw(m_quitIcon);

	/*m_helpIcon.setSize(sf::Vector2f(200, 80));
	m_helpIcon.setPosition(4.f, 4.f);
	window.draw(m_helpIcon);*/

	window.draw(text);
}

void Menu::drawPic(sf::RenderWindow& window)
{
	m_logoPic.setSize(sf::Vector2f(2000, 1850));
	
	window.draw(m_logoPic);
}

sf::RectangleShape& Menu::getStartIcon()
{
	return m_startIcon;
}

sf::RectangleShape& Menu::getQuitIcon()
{
	return m_quitIcon;
}

sf::RectangleShape& Menu::getHelpIcon()
{
	return m_helpIcon;
}

void Menu::setStartIconBound(sf::Color color)
{
	m_startIcon.setOutlineColor(color);
}

void Menu::setQuitIconBound(sf::Color color)
{
	m_quitIcon.setOutlineColor(color);
}

void Menu::setHelpIconBound(sf::Color color)
{
	m_helpIcon.setOutlineColor(color);
}

void Menu::drawWinPic(sf::RenderWindow& window)
{
	m_winPic.setSize(sf::Vector2f(1200, 900));
	window.draw(m_winPic);

	m_startIcon.setSize(sf::Vector2f(200, 80));
	m_startIcon.setPosition(900.f, 600.f);
	window.draw(m_startIcon);

	m_quitIcon.setSize(sf::Vector2f(200, 80));
	m_quitIcon.setPosition(900.f, 700.f);
	window.draw(m_quitIcon);
}

void Menu::drawLosePic(sf::RenderWindow& window)
{
	m_losePic.setSize(sf::Vector2f(1200, 900));
	window.draw(m_losePic);

	m_startIcon.setSize(sf::Vector2f(200, 80));
	m_startIcon.setPosition(150.f, 250.f);
	window.draw(m_startIcon);

	m_quitIcon.setSize(sf::Vector2f(200, 80));
	m_quitIcon.setPosition(150.f, 350.f);
	window.draw(m_quitIcon);
}

void Menu::drawHelpPic(sf::RenderWindow& window)
{
	m_helpPic.setSize(sf::Vector2f(1200, 900));
	window.draw(m_helpPic);

	m_startIcon.setSize(sf::Vector2f(200, 80));
	m_startIcon.setPosition(150.f, 250.f);
	window.draw(m_startIcon);

	m_quitIcon.setSize(sf::Vector2f(200, 80));
	m_quitIcon.setPosition(150.f, 350.f);
	window.draw(m_quitIcon);
}
