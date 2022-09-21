#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Perspective
{
public:
	Perspective();
	~Perspective();
	
	void switchView(int viewNum);
	void setViewPosition(sf::Vector2f position);
	void setViewSize(sf::Vector2f size);
	
	//Only important if following entity is enabled
	void transitionSpeed(float);
	void followEntity(bool isFollowing);
	//.getGlobalBounds()
	void follow(sf::FloatRect, sf::RenderWindow&);

	void addView();
	void addView(sf::Vector2f centerPosition);

private:
	int selectedView;
	bool followingEntity;
	sf::Vector2f windowSize;

	//Only important if followingEntity is true
	float lerpSpeed;

	std::vector<sf::View> views;

	void init();
};

