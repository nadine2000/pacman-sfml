#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.h"
#include "MovingObjectInclude/MovingObject.h"


class PacmanBase : public MovingObject
{

public:

	PacmanBase(sf::Vector2f position, sf::Vector2f size, GameTexture_t obj);

	void move(const float, sf::Vector2f) override;
	void setPosition(const sf::Vector2f);

private:

	sf::Vector2f dirFromKey();

};
