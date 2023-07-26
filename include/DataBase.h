#pragma once
#include <SFML/graphics.hpp>
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\SoundBuffer.hpp>
#include "AnimationData.h"

class DataBase
{
public:
	enum Objects
	{
		PlayerObj,
		Poisn,
		Monster,
		Wall,
		KeyObj,
		BlueDiamond,
		Gift,
		Door,
		Water,
		Coin,
		Max
	};
	enum Status {
		Win,
		Lose
	};

	static DataBase& instance();

	DataBase(const DataBase&) = delete;
	DataBase& operator=(const DataBase&) = delete;
	const sf::Texture& texture() const { return m_texture; }
	const AnimationData& animationData(Objects object) { return m_data[object]; }
	std::ifstream& loadLevelNames();
	~DataBase() = default;

private:
	DataBase();
	sf::Texture m_texture;
	std::vector<std::unique_ptr<sf::Texture>> m_statTexture;
	std::vector<AnimationData> m_data;
	std::vector<std::string>m_names;
	std::ifstream m_levelNames;
};