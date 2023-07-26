#pragma once
#include <vector>
#include <memory>
#include "CollisionHandler.h"
#include "DataBase.h"
#include "StaticObject.h"
#include "GlobalMonster.h"
#include "PlayerObj.h"
#include "Wall.h"
#include "Door.h"
#include "BlueDiamond.h"
#include "Gift.h"
#include "KeyObj.h"
#include "Monster.h"
#include "Poisn.h"
#include "Coin.h"
#include "Water.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <fstream>

class Board{
public:
	Board();
	void initPlayer(std::unique_ptr<PlayerObj>& , sf::Vector2f pos);
	void draw(sf::RenderTarget& window);
	void upLoadLevels();
	void readLevel(int ,std::unique_ptr<PlayerObj>&);
	void initialWall(sf::Vector2f pos);
	void initialDoor(sf::Vector2f pos);
	void initialBlueDiamond(sf::Vector2f pos);
	void initialKey(sf::Vector2f pos);
	void initialMonster(sf::Vector2f pos);
	void initialPoisn(sf::Vector2f pos);
	void intialCoin(sf::Vector2f pos);
	void initialWater(sf::Vector2f pos);
	void intialGift(sf::Vector2f pos);
	void initialGun(sf::Vector2f pos);
	float getCloserWall(float d);
	size_t getNumOfLevels() const { return (m_levels.size() -1); }
	void updateObjects(sf::Time delta);
	void clearVecs();
	void memberAndStatColl(PlayerObj& d);
	void memberAndmonsterColl(PlayerObj& d);
	void monsterAndStatColl();
	Menu& getMenu();
	~Board() = default;
private:
	std::vector<std::string> m_levels;
	sf::Text m_data;
	Menu m_menu;

	std::vector<std::unique_ptr<StaticObject>> m_statics;
	std::vector<std::unique_ptr<GlobalMonster>> m_monsters;
};

