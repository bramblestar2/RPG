#include "../Headers/Hitbox.h"
#include <iostream>
#include "../Headers/Misc.h"

Hitbox::Hitbox(sf::FloatRect a)
{
	hitbox = sf::RectangleShape(sf::Vector2f(a.width, a.height));
	hitbox.setPosition(a.left, a.top);
	init();
}

Hitbox::Hitbox()
{
	init();
}

Hitbox::~Hitbox()
{
}

sf::FloatRect Hitbox::getHitBox()
{
	return hitbox.getGlobalBounds();
}

bool Hitbox::collision(sf::FloatRect& a, sf::Vector2f& velocity)
{
	bool colliding = false;

	if (hitbox.getGlobalBounds().intersects(a))
	{
		//Bottom
		if (hitbox.getGlobalBounds().top < a.top &&
			hitbox.getGlobalBounds().top + hitbox.getGlobalBounds().height < a.top + a.height &&
			hitbox.getGlobalBounds().left < a.left + a.width &&
			hitbox.getGlobalBounds().left + hitbox.getGlobalBounds().width > a.left)
		{
			velocity.y = 0;
			//std::cout << "Bottom / ";
		}
		//Top
		else if (hitbox.getGlobalBounds().top > a.top &&
			hitbox.getGlobalBounds().top + hitbox.getGlobalBounds().height > a.top + a.height &&
			hitbox.getGlobalBounds().left < a.left + a.width &&
			hitbox.getGlobalBounds().left + hitbox.getGlobalBounds().width > a.left)
		{
			velocity.y = 0;
			//std::cout << "Top / ";
		}

		//Right
		if (hitbox.getGlobalBounds().left < a.left &&
			hitbox.getGlobalBounds().left + hitbox.getGlobalBounds().width < a.left + a.width &&
			hitbox.getGlobalBounds().top < a.top + a.height &&
			hitbox.getGlobalBounds().top + hitbox.getGlobalBounds().height > a.top)
		{
			velocity.x = 0;
			//std::cout << "Right / ";
		}
		//Left
		else if (hitbox.getGlobalBounds().left > a.left &&
			hitbox.getGlobalBounds().left + hitbox.getGlobalBounds().width > a.left + a.width &&
			hitbox.getGlobalBounds().top < a.top + a.height &&
			hitbox.getGlobalBounds().top + hitbox.getGlobalBounds().height > a.top)
		{
			velocity.x = 0;
			//std::cout << "Left";
		}

		//std::cout << std::endl;

		colliding = true;
	}

	return colliding;
}

void Hitbox::setFloatRect(sf::FloatRect a)
{
	hitbox.setSize(sf::Vector2f(a.width, a.height));
	hitbox.setPosition(a.left, a.top);
}

void Hitbox::prediction(sf::Vector2f velocity)
{
	sf::Vector2f predict = sf::Vector2f(hitbox.getPosition().x + (velocity.x * 2), 
										hitbox.getPosition().y + (velocity.y * 2));

	hitbox.setPosition(predict);
}

void Hitbox::showHitbox(sf::RenderWindow& window)
{
	window.draw(hitbox);
}

void Hitbox::init()
{
	collideX = -1;
	collideY = -1;

	hitbox.setOutlineColor(sf::Color::Blue);
	hitbox.setOutlineThickness(1);
	hitbox.setFillColor(sf::Color::Transparent);
}
