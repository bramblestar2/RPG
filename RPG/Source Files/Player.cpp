#include "../Headers/Player.h"
#include "../Dependencies/json.hpp"
#include "../Headers/Extra.h"
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

sf::FloatRect Player::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void Player::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Player::update(double dt)
{
	movement();

	sprite.move(velocity.x * (dt*100), velocity.y * (dt * 100));

	hitbox.setPosition(sprite.getPosition());
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
	std::ifstream ifs("settings.json");
	json info = json::parse(ifs);
	ifs.close();

	spriteFiles = info["Sprites"]["Player"];
	maxSpeed = info["Player"]["Speed"];
}

void Player::movement()
{
	//Transition speeds
	float speedUp = 0.4f;
	float slowDown = 0.2f;

	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (velocity.y > -maxSpeed)
			velocity.y = Extra::lerp(velocity.y, -maxSpeed, speedUp);
	}
	//Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (velocity.y < maxSpeed)
			velocity.y = Extra::lerp(velocity.y, maxSpeed, speedUp);
	}
	else
	{
		if (velocity.y != 0)
			velocity.y = Extra::lerp(velocity.y, 0, slowDown);
	}
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (velocity.x > -maxSpeed)
			velocity.x = Extra::lerp(velocity.x, -maxSpeed, speedUp);
	}
	//Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (velocity.x < maxSpeed)
			velocity.x = Extra::lerp(velocity.x, maxSpeed, speedUp);
	}
	//No keys held - Slow down to a stop
	else
	{
		if (velocity.x != 0)
			velocity.x = Extra::lerp(velocity.x, 0, slowDown);
	}
}