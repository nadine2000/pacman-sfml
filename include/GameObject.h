#pragma once

#include <SFML/Graphics.hpp>
#include "Global.h"

class GameObject
{

public:

	GameObject(sf::Vector2f position = sf::Vector2f(), 
		sf::Vector2f size = sf::Vector2f(),
		GameTexture_t obj = EmptyObj);

    void draw(sf::RenderWindow& window);
	sf::Sprite getSprite() const;

protected:

	sf::Vector2f m_position;
	sf::Sprite m_sprite;

};