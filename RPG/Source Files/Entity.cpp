#include "../Headers/Entity.h"
#include <iostream>

Entity::Entity()
{
	init();
}

Entity::~Entity()
{
}

sf::FloatRect Entity::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

sf::FloatRect Entity::getHitbox()
{
	return hitbox.getHitBox();
}

void Entity::updateCollision(sf::FloatRect aHitbox)
{
	hitbox.collision(aHitbox, velocity);
}

void Entity::update(double dt)
{
	movement();
}

void Entity::updateEvents(sf::Event event)
{
	
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Entity::init()
{
	hitbox = Hitbox(sprite.getGlobalBounds());
}

void Entity::updateHitbox()
{
	hitbox.setFloatRect(sprite.getGlobalBounds());
	hitbox.prediction(velocity);
}

void Entity::movement()
{
}
