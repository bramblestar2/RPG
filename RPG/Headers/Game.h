#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Perspective.h"
#include "Map.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void run();
	void render();
	void update();
	void updateDt();
	void updateSFMLEvents();
private:
	void initWindow();

	sf::Clock dtClock;
	double dt;

	sf::RenderWindow* window;
	sf::Event event;


	// Game stuff
	Player player;
	Map map;
	Perspective views;
};

