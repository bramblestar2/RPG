#include "../Headers/Map.h"
#include <iostream>
#include "../Headers/Misc.h"

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
	if (!enemies.empty())
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies.at(i)->update(dt);
		}
	}
}

void Map::updateEvents(sf::Event event)
{
	if (!enemies.empty())
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies.at(i)->updateEvents(event);
		}
	}
}

void Map::draw(sf::RenderWindow& window)
{
	if (!enemies.empty())
	{
		for (int i = 0; i < enemies.size(); i++)
			enemies.at(i)->draw(window);
	}
}

void Map::getPlayerInfo(sf::FloatRect a)
{
	collisionDetection(a);
}

void Map::init()
{
}

void Map::collisionDetection(sf::FloatRect playerHitbox)
{
	//Player and Enemy Collision Detection
	if (!enemies.empty())
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies.at(i)->updateCollision(playerHitbox);
		}
	}
}
