#pragma once
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include "DynamicObject.h"
#include "Data.h"
#include "DataBase.h"
#include "Board.h"
#include "PlayerObj.h"
#include "Poisn.h"
#include "Monster.h"
#include "Coin.h"
#include "Gift.h"

class Controller {
public:
	Controller();
	void run();
	void handleEvents(sf::Event& event);
	void winPos(sf::RenderWindow& window, sf::Event& e, float w);
	void updateObjects(sf::Time delta);
	void printBoard(sf::RenderTarget& window);
	void newLevel();
	void collision();
	void monsterAndStatColl();
	void memberAndStatColl();
	void memberAndMonsterColl();
	//void checkmemberOnAir();
	void gameOver(sf::RenderWindow& window, DataBase::Status);
	void moveWindow(sf::RenderWindow &window);
	void startMenuFunc(sf::RenderWindow& window);

	bool isMouseOver(sf::RenderWindow& window, sf::RectangleShape shape);

	~Controller() = default;
private:
	sf::RenderWindow m_window;
	sf::Clock m_timer;
	sf::Time m_moveTimer = sf::seconds(0.2f);
	Board m_board;
	Data m_data;
	float m_windowWidth = WIDTH;
	std::unique_ptr<PlayerObj> m_member;
	bool firstTime;

	bool isGameOpen = false;
	bool isHelpOpen = false;
};