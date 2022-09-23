#pragma once
#include <SFML/Graphics.hpp>

class Hitbox
{
public:
	Hitbox(sf::FloatRect);
	Hitbox();
	~Hitbox();

	sf::FloatRect getHitBox();

	bool collision(sf::FloatRect&, sf::Vector2f& velocity);

	void setFloatRect(sf::FloatRect);
	//Get the position of the entity and 
	//velocity from sprite for prediction
	void prediction(sf::Vector2f velocity);
	void showHitbox(sf::RenderWindow& window);
private:
	sf::RectangleShape hitbox;

	int collideX, collideY;

	void init();
};

