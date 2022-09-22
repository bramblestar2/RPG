#include "../Headers/Map.h"
#include <iostream>

Map::Map()
{
	enemies.push_back(new Enemy(500, 500));

	init();
}

Map::~Map()
{
	if (!enemies.empty())
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			delete enemies.at(i);
		}
		enemies.clear();
	}
}

void Map::update(float dt)
{
}

void Map::updateEvents(sf::Event)
{
}

void Map::draw(sf::RenderWindow& window)
{
	if (!enemies.empty())
	{
		for (int i = 0; i < enemies.size(); i++)
			enemies.at(i)->draw(window);
	}
}

void Map::getPlayerInfo(sf::FloatRect a, sf::Vector2f& b)
{
	collisionDetection(a, b);
}

void Map::init()
{
}

void Map::collisionDetection(sf::FloatRect playerHitbox, sf::Vector2f& playerVelocity)
{
	if (!enemies.empty())
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies.at(i)->updateCollision(playerHitbox, playerVelocity);
		}
	}
}
