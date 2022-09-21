#pragma once
#include <SFML/Graphics.hpp>

class Hitbox
{
public:
	Hitbox(sf::FloatRect);
	Hitbox();
	~Hitbox();

	sf::FloatRect getHitBox();
	bool collision(sf::FloatRect, sf::Vector2f& velocity);
	void setPosition(sf::Vector2f position);
	//Get the position of the entity and 
	//velocity from sprite for prediction
	void prediction(sf::Vector2f velocity);
	void showHitbox(sf::RenderWindow& window);
private:
	sf::RectangleShape hitbox;

	void init();
};

