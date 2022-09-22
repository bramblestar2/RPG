#include "../Headers/Enemy.h"
#include <iostream>

Enemy::Enemy(int x, int y)
{
	init();
	hitbox = Hitbox(sprite.getGlobalBounds());
	sprite.setPosition(x, y);
}

Enemy::Enemy()
{
	init();
}

Enemy::~Enemy()
{
}

void Enemy::update(double dt)
{
	hitbox.setPosition(sprite.getPosition());
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
