#include "../Headers/Enemy.h"

Enemy::Enemy(int x, int y)
{
	init();
	sprite.setPosition(x, y);
}

Enemy::Enemy()
{
	init();
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
}

void Enemy::updateEvents(sf::Event event)
{
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Enemy::init()
{
	isIdle = true;
	
	sprite.setSize(sf::Vector2f(60, 60));
	sprite.setFillColor(sf::Color::Red);
}

void Enemy::movement()
{
}

void Enemy::idle()
{
}
