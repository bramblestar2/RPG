#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	//level info, inventory, and player info
	//will be saved to saves.json
	void saveInfo();

	sf::FloatRect getGlobalBounds();
	void setPosition(sf::Vector2f);

	void update(double dt);
	void updateEvents(sf::Event);
	void draw(sf::RenderWindow& window);
private:
	void init();

	void movement();

	sf::Vector2f velocity;
	sf::RectangleShape sprite;
	sf::Texture t;

	Hitbox hitbox;

	bool showHitbox;
	float maxSpeed;

	//The location of the sprites
	std::string spriteFiles;
};