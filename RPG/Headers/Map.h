#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"

class Map
{
public:
	Map();
	~Map();

	void update(float);
	void updateEvents(sf::Event);
	void draw(sf::RenderWindow& window);

	void getPlayerInfo(sf::FloatRect hitbox, sf::Vector2f& velocity);

private:
	//Will gather all map information
	void init();

	//Handles all collision between entities
	void collisionDetection(sf::FloatRect, sf::Vector2f&);
	
	
	std::vector<Enemy*> enemies;
};