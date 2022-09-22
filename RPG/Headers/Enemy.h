#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(int x, int y);
	Enemy();
	~Enemy();

	virtual void update(double);
	virtual void updateEvents(sf::Event);
	virtual void draw(sf::RenderWindow& window);
private:
	virtual void init();

	virtual void movement();
	virtual void idle();

	sf::Clock movementTimer;

	sf::Vector2f velocity;
	sf::RectangleShape sprite;
	sf::Texture t;

	Hitbox hitbox;

	bool isIdle;
	bool showHitbox;
};

