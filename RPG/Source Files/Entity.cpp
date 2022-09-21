#include "../Headers/Entity.h"

Entity::Entity()
{
	init();
}

Entity::~Entity()
{
}

void Entity::updateCollision(sf::FloatRect aHitbox, sf::Vector2f aVelocity)
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
	hitbox.setPosition(sprite.getPosition());
	hitbox.prediction(velocity);
}

void Entity::movement()
{
}
