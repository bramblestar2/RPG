#include "../Headers/Game.h"
#include <fstream>
#include <iostream>
#include "../Dependencies/json.hpp"

using json = nlohmann::json;

Game::Game()
{
	views.followEntity(true);
	views.addView();
	views.transitionSpeed(0.1f);

	initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}

void Game::render()
{
	window->clear();

	map.draw(*window);

	//Player Renders
	player.draw(*window);

	window->display();
}

void Game::update()
{
	if (window->hasFocus())
	{
		views.follow(player.getGlobalBounds(), *window);
		player.update(dt);
		map.update(dt);
		collisions();
	}
}

void Game::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
			event.key.code == sf::Keyboard::Escape)
			window->close();

		if (event.type == sf::Event::KeyPressed)
		{
			player.updateEvents(event);
			map.updateEvents(event); 
		}
	}
}

void Game::initWindow()
{
	std::ifstream settings("Files/settings.json");
	json info = json::parse(settings);
	settings.close();

	std::string title = info["Window"]["Title"];
	window = new sf::RenderWindow(sf::VideoMode(
								  info["Window"]["Width"],
								  info["Window"]["Height"]),
								  title);
	window->setFramerateLimit(info["Window"]["FPS"]);
}

void Game::collisions()
{
	map.getPlayerInfo(player.getHitbox());
	
	//Check if enemies empty
	if (!map.returnEnemies().empty())
	{
		//If enemies isnt empty, go through the entire list
		for (int i = 0; i < map.returnEnemies().size(); i++)
		{
			player.updateCollision(map.returnEnemies().at(i)->getHitbox());
		}
	}
}
