#include "../Headers/Perspective.h"
#include <iostream>
#include <fstream>
#include "../Dependencies/json.hpp"
#include "../Headers/Misc.h"

using json = nlohmann::json;


Perspective::Perspective()
{
	init();
}

Perspective::~Perspective()
{
}

void Perspective::init()
{
	selectedView = 0;
	followingEntity = true;
	lerpSpeed = 0.5f;

	std::ifstream ifs("Files/settings.json");
	json info = json::parse(ifs);
	ifs.close();

	windowSize = sf::Vector2f(info["Window"]["Width"], 
							  info["Window"]["Height"]);
}

void Perspective::switchView(int viewNum)
{
	if (viewNum >= 0 && viewNum < views.size())
		selectedView = viewNum;
	else
		std::cout << "View number doesnt exist > " << viewNum << std::endl;
}

void Perspective::setViewPosition(sf::Vector2f position)
{
	views.at(selectedView).setCenter(position);
}

void Perspective::setViewSize(sf::Vector2f size)
{
	views.at(selectedView).setSize(size);
}

void Perspective::transitionSpeed(float speed)
{
	lerpSpeed = speed;
}

void Perspective::followEntity(bool isFollowing)
{
	followingEntity = isFollowing;
}

void Perspective::follow(sf::FloatRect a, sf::RenderWindow& window)
{
	int x = Misc::lerp(views.at(selectedView).getCenter().x, a.left+(a.width/2), lerpSpeed);
	int y = Misc::lerp(views.at(selectedView).getCenter().y, a.top + (a.height / 2), lerpSpeed);;
	views.at(selectedView).setCenter(x, y);

	window.setView(views.at(selectedView));
}

void Perspective::addView()
{
	views.push_back(sf::View());
	views.at(views.size() - 1).setSize(windowSize);
}

void Perspective::addView(sf::Vector2f centerPosition)
{
	views.push_back(sf::View());
	views.at(views.size() - 1).setSize(windowSize);
	views.at(views.size() - 1).setCenter(centerPosition);
}
