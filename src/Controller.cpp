#include "Controller.h"
#include "CollisionHandler.h"
#include <algorithm>

Controller::Controller()
	:m_data(1,0,3)
{
	m_window.create(sf::VideoMode(WIDTH, HEIGHT), "OOP", sf::Style::Fullscreen);
}

void Controller::run()
{
	m_data.setPos(WIDTH, HEIGHT);
	sf::Event event{};
	auto i = 0;
	startMenuFunc(m_window);

	sf::Texture back;
	back.loadFromFile("gameback.png");
	back.setSmooth(true);
	sf::RectangleShape spback;
	spback.setTexture(&back);
	spback.setSize(sf::Vector2f(5000, 5000));

	m_board.readLevel(i, m_member);

	while (m_window.isOpen())
	{
		moveWindow(m_window);

		if (m_member->isWin())
		{
			winPos(m_window , event ,m_windowWidth);
			i++;
			m_windowWidth -= WIDTH;
			moveWindow(m_window);

			if (i == m_board.getNumOfLevels())
			{
				moveWindow(m_window);
				gameOver(m_window ,DataBase::Win);
				sf::sleep(sf::seconds(1));
				break;
				m_window.close();
			}
			else
				newLevel();
				m_board.readLevel(i, m_member);
		}		
		if (m_member.get()->killed())
		{
			gameOver(m_window, DataBase::Lose);
			break;
		}
		m_window.clear(sf::Color::Blue);
		m_window.draw(spback);
		handleEvents(event);
		printBoard(m_window);
		collision();
		moveWindow(m_window);
		m_member->direction(event.key.code);
		
		m_window.display();

		auto delta = m_timer.restart();
		m_member->update(delta);
		updateObjects(delta);
		
		m_data.updateLvl(i+1);
	}
}

void Controller::handleEvents(sf::Event& event)
{
	if (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_window.close();
				break;
			}
		}
	}
}

void Controller::winPos(sf::RenderWindow& window, sf::Event& e, float w)
{
	newLevel();
	m_board.readLevel(2, m_member);
	while (window.isOpen())
	{
		moveWindow(m_window);
		while (m_member->getSprite().getPosition().x < m_windowWidth)
		{
			window.clear();
			handleEvents(e);
			printBoard(m_window);
			auto delta = m_timer.restart();
			m_member->winMove(delta, Direction::Right);
			window.display();
		}
		return;
	}
}

void Controller::updateObjects(sf::Time delta)
{
	m_board.updateObjects(delta);
}
void Controller::printBoard(sf::RenderTarget& window)
{
	m_member->draw(window);
	m_board.draw(window);
	m_data.draw(m_window);
}
void Controller::newLevel()
{
	m_data.updateScore(m_data.getLastScore());
	m_board.clearVecs();
	m_member.reset(nullptr);
	m_windowWidth = WIDTH;
}

void Controller::collision()
{
	memberAndStatColl();
	//checkmemberOnAir();
	memberAndMonsterColl();
	monsterAndStatColl();
}

void Controller::monsterAndStatColl()
{
	m_board.monsterAndStatColl();
}

void Controller::memberAndStatColl()
{
	m_member->setCollisionX(false);
	m_member->setCollisionY(false);
	m_board.memberAndStatColl(*m_member);
	
	m_data.updateLives(m_member->getLive());
	auto score = m_member->getScore();
	m_data.updateScore(score);
}

void Controller::memberAndMonsterColl()
{
	m_board.memberAndmonsterColl(*m_member);
	m_data.updateLives(m_member->getLive());
}

/*void Controller::checkmemberOnAir()
{
	float dis;
	float memberY = m_member->getRect().top;
	for (int i = 0; i < m_board.m_statics.size(); ++i)
	{
		if (typeid(*m_board.m_statics[i]) == typeid(Wall))
		{
			float wallY = m_board.m_statics[i]->getSprite().getGlobalBounds().top;
			float YDistance = abs(wallY - memberY);
			if (YDistance >900 && wallY > memberY && !m_member->getCollisionY())
			{
				m_member->setOnAir(true);
				break;
			}	
		}
	}
	if (m_member->isOnAir())
	{
		dis = m_board.getCloserWall(memberY);
		m_member->moveDown(dis);
	}
}*/

void Controller::gameOver(sf::RenderWindow& window, DataBase::Status s)
{
	sf::Texture win;
	win.loadFromFile("win.jpeg");
	sf::Sprite spWin;
	spWin.setTexture(win);
	spWin.setPosition(0,0);

	sf::Texture lose;
	sf::Sprite spLose;
	lose.loadFromFile("lose.jpg");
	spLose.setTexture(lose);
	spLose.setPosition(100,100);

	switch (s)
	{
	case DataBase::Win:
		window.clear();
		window.draw(spWin);
		window.display();
		sf::sleep(sf::seconds(1));
		break;
	case DataBase::Lose:
		window.clear();
		window.draw(spLose);
		window.display();
		sf::sleep(sf::seconds(1));
		
		break;
	}
}

void Controller::moveWindow(sf::RenderWindow& window)
{
	Direction dir;
	if (m_member->getSprite().getPosition().x > m_windowWidth && m_member->getSprite().getPosition().x < (2 * m_windowWidth) && m_windowWidth <= WIDTH)
	{
		auto view = window.getView();
		dir = Direction::Right;
		view.move(toVector(dir) * m_windowWidth);
		window.setView(view);
		m_windowWidth += WIDTH;

		m_data.setPos(m_windowWidth, HEIGHT);
	}
	else if (m_member->getSprite().getPosition().x <= m_windowWidth - WIDTH && m_member->getSprite().getPosition().x >0)
	{
		m_windowWidth -= WIDTH;
		auto view = window.getView();
		Direction dir;
		dir = Direction::Left;
		view.move(toVector(dir) * (float)m_windowWidth);
		window.setView(view);
		m_data.setPos(m_windowWidth, HEIGHT);
	}
}

void Controller::startMenuFunc(sf::RenderWindow& window) //starting screen menu
{

	while (window.isOpen())
	{
		window.clear();


		m_board.getMenu().drawPic(window);
		m_board.getMenu().drawOptions(window);

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:

				if (isMouseOver(window, m_board.getMenu().getQuitIcon())) //quit game button pressed
					window.close();

				if (isMouseOver(window, m_board.getMenu().getStartIcon())) //start game button pressed
				{
					window.clear();
					isGameOpen = true;
				}
				if (isMouseOver(window, m_board.getMenu().getHelpIcon())) //help game button pressed
				{
					window.clear();
					isHelpOpen = true;
				}

				break;

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;

			case sf::Event::MouseMoved: //colorized buttons
				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
					m_board.getMenu().setStartIconBound(sf::Color::Yellow);
				else
					m_board.getMenu().setStartIconBound(sf::Color::Black);

				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					m_board.getMenu().setQuitIconBound(sf::Color::Yellow);
				else
					m_board.getMenu().setQuitIconBound(sf::Color::Black);

				if (isMouseOver(window, m_board.getMenu().getHelpIcon()))
					m_board.getMenu().setHelpIconBound(sf::Color::Yellow);
				else
					m_board.getMenu().setHelpIconBound(sf::Color::Black);
			}
		}
		if (isGameOpen || isHelpOpen)
			break;

		window.display();
	}
}

bool Controller::isMouseOver(sf::RenderWindow& window, sf::RectangleShape shape)
{
	sf::FloatRect shapePos = shape.getGlobalBounds();

	if (shapePos.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		return true;
	return false;
}
