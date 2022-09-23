#include "../Headers/Enemy.h"
#include <iostream>

Enemy::Enemy(int x, int y)
{
	init();
	sprite.setPosition(x, y);
	hitbox = Hitbox(sprite.getGlobalBounds());
}

Enemy::Enemy()
{
	init();
}

Enemy::~Enemy()
{
}

sf::FloatRect Enemy::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

sf::FloatRect Enemy::getHitbox()
{
	return hitbox.getHitBox();
}

void Enemy::updateCollision(sf::FloatRect aHitbox, sf::Vector2f& aVelocity)
{
	hitbox.collision(aHitbox, aVelocity);
}

void Enemy::update(double dt)
{
	
	hitbox.setFloatRect(sprite.getGlobalBounds());
	hitbox.prediction(velocity);
}

void Enemy::updateEvents(sf::Event event)
{
	if (event.key.code == sf::Keyboard::H)
	{
		if (showHitbox)
			showHitbox = false;
		else
			showHitbox = true;
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	if (showHitbox)
		hitbox.showHitbox(window);
}

void Enemy::init()
{
	isIdle = true;
	showHitbox = false;
	
	sprite.setSize(sf::Vector2f(60, 60));
	sprite.setFillColor(sf::Color::Red);
}

void Enemy::movement()
{
}

void Enemy::idle()
{
}
