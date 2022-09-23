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
	return sf::FloatRect(100, 100, 100, 100);
	//return hitbox.getHitBox();
}

void Entity::updateCollision(sf::FloatRect aHitbox, sf::Vector2f& aVelocity)
{
	hitbox.collision(aHitbox, aVelocity);
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
