#include "CollisionHandler.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "PlayerObj.h"
#include "GlobalMonster.h"
#include "Monster.h"
#include "Wall.h"
#include "Poisn.h"
#include "Door.h"
#include "Water.h"
#include "BlueDiamond.h"
#include "Coin.h"
#include "Gift.h"
#include "KeyObj.h"

namespace {

	void memberWall(GameObject& Player, GameObject& wall)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(Player);

		float memberX = member.getSprite().getGlobalBounds().left;
		float memberY = member.getSprite().getGlobalBounds().top;
		float wallX = wall.getSprite().getGlobalBounds().left;
		float wallY = wall.getSprite().getGlobalBounds().top;

		float XDistance = abs(wallX - memberX);
		float YDistance = abs(wallY - memberY);

		float stepX = member.getStep().x;
		float stepY = member.getStep().y;

		//left and right wall.
		if (XDistance < OBJECTSIZE && YDistance < OBJECTSIZE
			&& (stepX < 0 && wallX < memberX)
			&& !member.getCollisionX())
		{
			member.setXStep(10);
			member.setCollisionX(true);
		}
		if (XDistance < OBJECTSIZE && YDistance < OBJECTSIZE
			&& (stepX > 0 && wallX > memberX)
			&& !member.getCollisionX())
		{
			member.setXStep(-10);
			member.setCollisionX(true);
		}
		//over and under him wall.
		if (YDistance < OBJECTSIZE && XDistance < OBJECTSIZE
			&& (stepY < 0 && wallY < memberY) && !member.getCollisionY())
		{
			member.setYStep(10);
			member.setCollisionY(true);
		}
		if (YDistance < OBJECTSIZE && XDistance < OBJECTSIZE
			&& (stepY > 0 && wallY > memberY)
			&& !member.getCollisionY())
		{
			member.setYStep(-10);
			member.setCollisionY(true);
		}
		
	}
	void Wallmember(GameObject& player, GameObject& wall)
	{
		memberWall(player, wall);
	}
	//--------------------------------------------
	void MonsterWall(GameObject& monster,GameObject& staticWall)
	{
		Monster& mon= dynamic_cast<Monster&>(monster);
	}
	void WallMonster(GameObject& staticWall,GameObject& monster)
	{
		MonsterWall(monster, staticWall);
	}
	//-----------------------------------------------
	void PlayerDoor(GameObject& player,	GameObject& doorObject)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(player);

		if (member.isGobletTaken())
			member.setWon(true);
	}
	void DoorPlayer(GameObject& player, GameObject& door)
	{
		PlayerDoor(player, door);
	}
	//-------------------------------------------------
	void PlayerKill(GameObject& player, GameObject& StaticObject)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(player);
		member.decreaseLive();
	}
	void KillPlayer(GameObject& StaticObject,GameObject& Player)
	{
		PlayerKill(Player, StaticObject);
	}	
	//------------------------------------------------
	void PlayerDiamond(GameObject& player, GameObject& dia)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(player);
		member.addScore(100);

	}
	void DiamondPlayer(GameObject& dia, GameObject& member)
	{
		PlayerDiamond(member, dia);
	}
	//----------------------------------------------------
	void PlayerGift(GameObject& player, GameObject& dia)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(player);
		member.addScore(200);
	}
	void GiftPlayer(GameObject& dia, GameObject& member)
	{
		PlayerGift(member, dia);
	}
	//------------------------------------------------
	void PlayerKey(GameObject& player, GameObject& goblet)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(player);
		member.setGobletTaken(true);
	}
	void KeyPlayer(GameObject& player, GameObject& goblet)
	{
		PlayerKey(player, goblet);
	}
	//--------------------------------------------------------	
	void PlayerMonsterKill(GameObject& player,GameObject& monster)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(player);
		Monster& mons = dynamic_cast<Monster&>(monster);
		mons.setKill(true);
	}
	void MonsterPlayerKill(GameObject& monster, GameObject& player)
	{
		PlayerMonsterKill(player, monster);
	}
	//--------------------------------------------------------
	void PlayerCoin(GameObject& player, GameObject& coin)
	{
		PlayerObj& member = dynamic_cast<PlayerObj&>(player);
		
		member.addScore(50);
	}
	void CoinPlayer(GameObject& player, GameObject& coin)
	{
		PlayerCoin(player, coin);
	}
	//--------------------------------------------------------
	using HitFunctionPtr = void(*)(GameObject&, GameObject&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;
	
	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(PlayerObj), typeid(Wall))] = &memberWall;
		phm[Key(typeid(Wall), typeid(PlayerObj))] = &Wallmember;

		phm[Key(typeid(PlayerObj), typeid(BlueDiamond))] = &PlayerDiamond;
		phm[Key(typeid(BlueDiamond), typeid(PlayerObj))] = &DiamondPlayer;

		phm[Key(typeid(PlayerObj), typeid(Coin))] = &PlayerCoin;
		phm[Key(typeid(Coin), typeid(PlayerObj))] = &CoinPlayer;
		
		phm[Key(typeid(PlayerObj), typeid(Gift))] = &PlayerGift;
		phm[Key(typeid(Gift), typeid(PlayerObj))] = &GiftPlayer;

		phm[Key(typeid(PlayerObj), typeid(Door))] = &PlayerDoor;
		phm[Key(typeid(Door), typeid(PlayerObj))] = &DoorPlayer;
		
		phm[Key(typeid(PlayerObj), typeid(KeyObj))] = &PlayerKey;
		phm[Key(typeid(KeyObj), typeid(PlayerObj))] = &KeyPlayer;

		phm[Key(typeid(PlayerObj), typeid(Poisn))] = &PlayerKill;
		phm[Key(typeid(Poisn), typeid(PlayerObj))] = &KillPlayer;

		phm[Key(typeid(PlayerObj), typeid(Water))] = &PlayerKill;
		phm[Key(typeid(Water), typeid(PlayerObj))] = &KillPlayer;
		
		phm[Key(typeid(PlayerObj), typeid(Monster))] = &PlayerMonsterKill;
		phm[Key(typeid(Monster), typeid(PlayerObj))] = &MonsterPlayerKill;

		phm[Key(typeid(Monster), typeid(Wall))] = &MonsterWall;
		phm[Key(typeid(Wall), typeid(Monster))] = &WallMonster;
		phm[Key(typeid(Monster), typeid(Coin))] = &MonsterWall;
		phm[Key(typeid(Coin), typeid(Monster))] = &WallMonster;
		phm[Key(typeid(Monster), typeid(BlueDiamond))] = &MonsterWall;
		phm[Key(typeid(BlueDiamond), typeid(Monster))] = &WallMonster;
		phm[Key(typeid(Monster), typeid(Gift))] = &MonsterWall;
		phm[Key(typeid(Gift), typeid(Monster))] = &WallMonster;
		phm[Key(typeid(Monster), typeid(Door))] = &MonsterWall;
		phm[Key(typeid(Door), typeid(Monster))] = &WallMonster;
		phm[Key(typeid(Monster), typeid(KeyObj))] = &MonsterWall;
		phm[Key(typeid(KeyObj), typeid(Monster))] = &WallMonster;
	
		return phm;
	}
	
	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}
}


bool isCollision(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
	sf::FloatRect temp = { obj1.left - 1, obj1.top - 2, obj1.width - 2, obj1.height - 2 };
	//in order to check the next move
	sf::FloatRect newRec = { obj2.left + 1.f,
							obj2.top + 2.f,
							obj2.width, obj2.height - 2 };
	return (temp.intersects(newRec));
}

void processCollision(GameObject& object1, GameObject& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		throw UnknownCollision(object1, object2);
	}
	phf(object1, object2);
}
