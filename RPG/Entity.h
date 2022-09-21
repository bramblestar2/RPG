#pragma once
#include "Hitbox.h"

class Entity
{
public:
	Entity();
	~Entity();

	virtual void updateCollision(sf::FloatRect hitbox, sf::Vector2f velocity);
	virtual void update(double dt);
	virtual void updateEvents(sf::Event);
	virtual void draw(sf::RenderWindow& window);
private:
	virtual void init();
	virtual void updateHitbox();

	virtual void movement();

	sf::Vector2f velocity;
	sf::RectangleShape sprite;
	sf::Texture t;

	Hitbox hitbox;
};

