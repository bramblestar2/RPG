#include "Game.h"
#include <fstream>
#include <iostream>
#include "Dependencies/json.hpp"

using json = nlohmann::json;

Game::Game()
{
	views.followEntity(true);
	views.addView();
	views.transitionSpeed(0.5f);

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

	//Player Renders
	player.draw(*window);

	window->display();
}

void Game::update()
{
	//views.follow(player.getGlobalBounds(), *window);
	player.update(dt);
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
		}
	}
}

void Game::initWindow()
{
	std::ifstream settings("settings.json");
	json info = json::parse(settings);
	settings.close();

	std::string title = info["Window"]["Title"];
	window = new sf::RenderWindow(sf::VideoMode(info["Window"]["Width"], info["Window"]["Height"]), title);
	window->setFramerateLimit(info["Window"]["FPS"]);
}
