#include "../Headers/Player.h"
#include "../Dependencies/json.hpp"
#include "../Headers/Misc.h"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

Player::Player()
{
	//Player sprite 60x60 pixels
	sprite.setSize(sf::Vector2f(60, 60));
	sprite.setFillColor(sf::Color::White);

	hitbox = Hitbox(sprite.getGlobalBounds());
	showHitbox = false;

	init();
}

Player::~Player()
{
}

void Player::updateCollision(sf::FloatRect aHitbox)
{
	hitbox.collision(aHitbox, velocity);
}

sf::FloatRect Player::getHitbox()
{
	return hitbox.getHitBox();
}

sf::Vector2f& Player::getVelocity()
{
	return velocity;
}

sf::FloatRect Player::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

void Player::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Player::update(double dt)
{
	sprite.move(velocity.x * (dt * 100), velocity.y * (dt * 100));

	movement();

	hitbox.setFloatRect(sprite.getGlobalBounds());
	hitbox.prediction(velocity);
}

void Player::updateEvents(sf::Event event)
{
	if (event.key.code == sf::Keyboard::H)
	{
		if (showHitbox)
			showHitbox = false;
		else
			showHitbox = true;
	}
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	if (showHitbox)
		hitbox.showHitbox(window);
}

void Player::init()
{
	std::ifstream ifs("Files/settings.json");
	json info = json::parse(ifs);
	ifs.close();

	spriteFiles = info["Sprites"]["Player"];
	maxSpeed = info["Player"]["Speed"];
}

void Player::movement()
{
	//Transition speeds
	float speedUp = 0.4f;
	float slowDown = 0.3f;

	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (velocity.y > -maxSpeed)
			velocity.y = Misc::lerp(velocity.y, -maxSpeed, speedUp);
	}
	//Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (velocity.y < maxSpeed)
			velocity.y = Misc::lerp(velocity.y, maxSpeed, speedUp);
	}
	else
	{
		if (velocity.y != 0)
			velocity.y = Misc::lerp(velocity.y, 0, slowDown);
	}
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (velocity.x > -maxSpeed)
			velocity.x = Misc::lerp(velocity.x, -maxSpeed, speedUp);
	}
	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (velocity.x < maxSpeed)
			velocity.x = Misc::lerp(velocity.x, maxSpeed, speedUp);
	}
	//No keys held - Slow down to a stop
	else
	{
		if (velocity.x != 0)
			velocity.x = Misc::lerp(velocity.x, 0, slowDown);
	}
}