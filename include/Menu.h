#pragma once
#include <SFML/Graphics.hpp>
#include <typeinfo>


class Menu
{
public:
	Menu(); //constructor
	~Menu() = default;
	void getText();
	void helpPic();
	void getWinLosePic();
	void getButton();
	void drawOptions(sf::RenderWindow&);
	void drawPic(sf::RenderWindow&);
	sf::RectangleShape& getStartIcon();
	void setStartIconBound(sf::Color);
	sf::RectangleShape& getQuitIcon();
	sf::RectangleShape& getHelpIcon();
	void setQuitIconBound(sf::Color);

	void setHelpIconBound(sf::Color color);

	void drawWinPic(sf::RenderWindow&);
	void drawLosePic(sf::RenderWindow&);

	void drawHelpPic(sf::RenderWindow& window);


private:

	sf::Texture m_startGame;
	sf::Texture m_quit;
	sf::Texture m_help;
	sf::Texture m_pic;
	sf::Texture m_logo;
	sf::Texture m_win;
	sf::Texture m_lose;
	sf::Texture m_helpT;

	sf::RectangleShape m_startIcon;
	sf::RectangleShape m_quitIcon;
	sf::RectangleShape m_helpIcon;
	sf::RectangleShape m_picIcon;
	sf::RectangleShape m_logoPic;

	sf::Font m_font;
	sf::Text text;

	sf::RectangleShape m_winPic;
	sf::RectangleShape m_losePic;
	sf::RectangleShape m_helpPic;
	sf::RectangleShape m_keyPic;

};