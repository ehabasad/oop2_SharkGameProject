#include "DataBase.h"
#include "Direction.h"
#include <stdexcept>

//get the level names file
std::ifstream& DataBase::loadLevelNames() {
	return m_levelNames;
}

namespace
{
    AnimationData memberData()
    {
      
        const auto size = sf::Vector2i(57, 143);
        const auto initSpace = sf::Vector2i(46, 511);
        const auto middleSpace = sf::Vector2i(62, 0);
       

        auto member = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };


        member.m_data[Direction::Down].emplace_back(currentStart, size);
        member.m_data[Direction::Down].emplace_back(nextStart(), size);


        const auto size1 = sf::Vector2i(142, 35);
        const auto initSpace1 = sf::Vector2i(232, 523);
        const auto middleSpace1 = sf::Vector2i(13, 0);

        auto currentStart1 = initSpace1;

        auto nextStart1 = [&]()
        {
            currentStart1 += middleSpace1;
            currentStart1.x += size1.x;
            return currentStart1;
        };

        member.m_data[Direction::Left].emplace_back(currentStart1, size1);
        member.m_data[Direction::Left].emplace_back(nextStart1(), size1);
        member.m_data[Direction::Right].emplace_back(nextStart1(), size1);
        member.m_data[Direction::Right].emplace_back(nextStart1(), size1);

        
        const auto size2 = sf::Vector2i(57, 143);
        const auto initSpace2 = sf::Vector2i(852, 515);
        const auto middleSpace2 = sf::Vector2i(44, 0);

        auto currentStart2 = initSpace2;

        auto nextStart2 = [&]()
        {
            currentStart2 += middleSpace2;
            currentStart2.x += size2.x;
            return currentStart2;
        };
        
        member.m_data[Direction::Up].emplace_back(currentStart2, size2);
        member.m_data[Direction::Up].emplace_back(nextStart2(), size2);

        return member;
    }
    AnimationData PoisnData()
    {
        const auto size = sf::Vector2i(9, 14);
        const auto initSpace = sf::Vector2i(3, 275);
        const auto middleSpace = sf::Vector2i(5, 0);

        auto fire = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        fire.m_data[Direction::Right].emplace_back(currentStart, size);
        fire.m_data[Direction::Right].emplace_back(nextStart(), size);
        fire.m_data[Direction::Right].emplace_back(nextStart(), size);
        fire.m_data[Direction::Right].emplace_back(nextStart(), size);
        fire.m_data[Direction::Right].emplace_back(nextStart(), size);
        fire.m_data[Direction::Right].emplace_back(nextStart(), size);
        fire.m_data[Direction::Right].emplace_back(nextStart(), size);

        return fire;    
    }
    AnimationData monsterData()
    {
        const auto size = sf::Vector2i(59, 31);
        const auto initSpace = sf::Vector2i(1, 355);
        const auto middleSpace = sf::Vector2i(2, 0);

        auto monster = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        monster.m_data[Direction::Right].emplace_back(currentStart, size);
        monster.m_data[Direction::Right].emplace_back(nextStart(), size);
        monster.m_data[Direction::Down].emplace_back(nextStart(), size);
        monster.m_data[Direction::Down].emplace_back(nextStart(), size);
        monster.m_data[Direction::Left].emplace_back(nextStart(), size);
        monster.m_data[Direction::Left].emplace_back(nextStart(), size);
        monster.m_data[Direction::Up].emplace_back(nextStart(), size);
        monster.m_data[Direction::Up].emplace_back(nextStart(), size);

        return monster;
    }
    AnimationData gobletData()
    {
        const auto size = sf::Vector2i(20, 20);
        const auto initSpace = sf::Vector2i(9,395);
        const auto middleSpace = sf::Vector2i(18, 0);

        auto goblet = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            //currentStart.y += size.y;
            return currentStart;
        };

        goblet.m_data[Direction::Right].emplace_back(currentStart, size);
        goblet.m_data[Direction::Right].emplace_back(nextStart(), size);
        goblet.m_data[Direction::Right].emplace_back(nextStart(), size);
        goblet.m_data[Direction::Right].emplace_back(nextStart(), size);
       /* goblet.m_data[Direction::Right].emplace_back(nextStart(), size);
        goblet.m_data[Direction::Right].emplace_back(nextStart(), size);
        goblet.m_data[Direction::Right].emplace_back(nextStart(), size);
        goblet.m_data[Direction::Right].emplace_back(nextStart(), size);
        goblet.m_data[Direction::Right].emplace_back(nextStart(), size);*/

        return goblet;
    }
    AnimationData wallData()
    {
        const auto size = sf::Vector2i(25, 25);
        const auto initSpace = sf::Vector2i(3,674);

        auto wall = AnimationData{};
        auto currentStart = initSpace;
        
        wall.m_data[Direction::Right].emplace_back(currentStart, size);

        return wall;
    }
    AnimationData doorData()
    {
        const auto size = sf::Vector2i(43, 49);
        const auto initSpace = sf::Vector2i(14,176);

        auto door = AnimationData{};
        auto currentStart = initSpace;
        
        door.m_data[Direction::Right].emplace_back(currentStart, size);

        return door;
    } 
    AnimationData blueDiamondData()
    {
        const auto size = sf::Vector2i(14, 12);
        const auto initSpace = sf::Vector2i(6,317);

        auto BlueDiamond = AnimationData{};
        auto currentStart = initSpace;
        
        BlueDiamond.m_data[Direction::Right].emplace_back(currentStart, size);

        return BlueDiamond;
    } 
    AnimationData giftData()
    {
        const auto size = sf::Vector2i(16, 13);
        const auto initSpace = sf::Vector2i(6,462);

        auto redDiamond = AnimationData{};
        auto currentStart = initSpace;
        
        redDiamond.m_data[Direction::Right].emplace_back(currentStart, size);

        return redDiamond;
    }
    AnimationData coinData()
    {
        const auto size = sf::Vector2i(11, 11);
        const auto initSpace = sf::Vector2i(6, 231);
        const auto middleSpace = sf::Vector2i(7, 0);

        auto rock = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        rock.m_data[Direction::Right].emplace_back(currentStart, size);
        rock.m_data[Direction::Right].emplace_back(nextStart(), size);
        rock.m_data[Direction::Right].emplace_back(nextStart(), size);
        rock.m_data[Direction::Right].emplace_back(nextStart(), size);

        return rock;
    }

    AnimationData waterData()
    {
        const auto size = sf::Vector2i(35, 31);
        const auto initSpace = sf::Vector2i(2,416 );
        const auto middleSpace = sf::Vector2i(0.5, 0);

        auto water = AnimationData{};
        auto currentStart = initSpace;
        
        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        water.m_data[Direction::Right].emplace_back(currentStart, size);
        water.m_data[Direction::Right].emplace_back(nextStart(), size);
        water.m_data[Direction::Right].emplace_back(nextStart(), size);
        water.m_data[Direction::Right].emplace_back(nextStart(), size);
        water.m_data[Direction::Right].emplace_back(nextStart(), size);
        water.m_data[Direction::Right].emplace_back(nextStart(), size);


        return water;
    }
}

DataBase& DataBase::instance()
{
    static DataBase instance;
    return instance;
}

DataBase::DataBase()
    : m_data(Max),m_levelNames("levelNames.txt")
{
    if (!m_texture.loadFromFile("spritesheet5.png"))
    {
        throw std::runtime_error("Can't load file");
    }

    m_data[PlayerObj] = memberData();
    m_data[Poisn] = PoisnData();
    m_data[Monster] = monsterData();     
    m_data[KeyObj] = gobletData(); 
    m_data[Wall] = wallData();
    m_data[BlueDiamond] = blueDiamondData();
    m_data[Gift] = giftData();
    m_data[Coin] = coinData();
    m_data[Door] = doorData();
    m_data[Water] = waterData();
}