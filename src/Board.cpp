#include "Board.h"
#include <algorithm>

Board::Board()
{
	this->upLoadLevels();
}

void Board::initPlayer(std::unique_ptr<PlayerObj> &member, sf::Vector2f pos)
{
	member = std::make_unique<PlayerObj>(pos);
}

void Board::draw(sf::RenderTarget& window)
{
	for (auto& stat : m_statics)
		stat->draw(window);
	for (auto& monst : m_monsters)
		monst->draw(window);
}

void Board::upLoadLevels()
{
	auto inpFile = &DataBase::instance().loadLevelNames();
	std::string levelName;
	
	while (std::getline(*inpFile, levelName))
	{
		m_levels.push_back(levelName);
	}

	//while (!inpFile->eof())
	//{
	//	std::getline(*inpFile, levelName);
	//	m_levels.push_back(levelName);
	//}
	inpFile->close();
}

void Board::readLevel(int lev , std::unique_ptr<PlayerObj> &member )
{
	
	if (lev < m_levels.size())
	{
		std::ifstream levelFile;
		levelFile.open(m_levels[lev]);
		if (!levelFile.is_open())
			exit(EXIT_FAILURE);
		int x, y;
		levelFile >> x >> y;
		char c;
		
		for (auto i = 0; i < x; ++i)
		{
			for (auto j = 0; j < y; ++j)
			{
				sf::Vector2f pos = { (float)(j*100) , (float)((i+1)*100) };
				
				c = levelFile.get();
				if (c == '\n') {
					j--;
					continue;
				}
				switch (c)
				{
				case '/':
					if(!member)
						initPlayer(member,pos);
					break;
				case '#':
					initialWall(pos);
					break;
				case 'D':
					initialDoor(pos);
					break;
				case '+':
					initialBlueDiamond(pos);
					break;
				case 'k':
					initialKey(pos);
					break;
				case '!':
					initialMonster(pos);
					break;
				case 'f':
					initialPoisn(pos);
					break;
				case '@':
					intialCoin(pos);
					break;
				case 'w' :
					initialWater(pos);
					break;
				case 'R' :
					intialGift(pos);
					break;
				default:
					break;
				}
			}
		}
		levelFile.close();
	}
}

void Board::initialWall(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<Wall>(pos));
}

void Board::initialDoor(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<Door>(pos));
}

void Board::initialBlueDiamond(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<BlueDiamond>(pos));
}

void Board::initialKey(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<KeyObj>(pos));
}

void Board::initialMonster(sf::Vector2f pos)
{
	m_monsters.emplace_back(std::make_unique<Monster>(pos));
}

void Board::initialPoisn(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<Poisn>(pos));
}

void Board::intialCoin(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<Coin>(pos));
}

void Board::initialWater(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<Water>(pos));
}

void Board::intialGift(sf::Vector2f pos)
{
	m_statics.emplace_back(std::make_unique<Gift>(pos));
}

float Board::getCloserWall(float d)
{
	float minDist = 2000;
	for (const auto& stat : m_statics)
	{
		if(typeid(*stat) == typeid(Wall))
		{ 
			auto wallY=stat.get()->getSprite().getGlobalBounds().top;
			auto memberY = d;
			auto Ydistance = abs(wallY - memberY);
			if (Ydistance < minDist)
				minDist = Ydistance;
		}
	}
	return minDist;
}

void Board::updateObjects(sf::Time delta)
{
	for (const auto& stat : m_statics)
		stat->update(delta);
	for (const auto& monst : m_monsters)
		monst->update(delta);
}

void Board::clearVecs()
{
	m_statics.clear();
	m_monsters.clear();
}

void Board::memberAndStatColl(PlayerObj& d)
{
	int collisionTimes = 0;
	PlayerObj& member = dynamic_cast<PlayerObj&>(d);
	for (int i = 0; i < m_statics.size(); ++i)
	{
		if (isCollision(m_statics[i]->getRect(), member.getRect()))
		{
			processCollision(member, *m_statics[i]);
			collisionTimes++;
			if (typeid(*m_statics[i]) == typeid(Wall) || typeid(*m_statics[i]) == typeid(Coin)
				|| typeid(*m_statics[i]) == typeid(Door))
				continue;
			else if (typeid(*m_statics[i]) == typeid(Poisn)
				|| typeid(*m_statics[i]) == typeid(Water))
			{
				member.decreaseLive();
			}
			else
				m_statics.erase(m_statics.begin() + i);
		}
		if (collisionTimes >= 1)
			break;
	}
}

void Board::memberAndmonsterColl(PlayerObj& d)
{
	PlayerObj& member = dynamic_cast<PlayerObj&>(d);
	for (int i = 0; i < m_monsters.size(); ++i)
	{
		if (isCollision(m_monsters[i]->getRect(), member.getRect()))
		{
			processCollision(member, *m_monsters[i]);
			m_monsters.erase(m_monsters.begin() + i);
			member.decreaseLive();
		}
	}
}

void Board::monsterAndStatColl()
{
	for (auto& monst : m_monsters)
	{
		for (int i = 0; i < m_statics.size(); ++i)
		{
			if (isCollision(m_statics[i]->getRect(), monst->getRect()))
			{
				processCollision(*monst, *m_statics[i]);
				monst->setCollisionX(true);
			}
		}
	}
}

Menu& Board::getMenu()
{
	return m_menu;
}
