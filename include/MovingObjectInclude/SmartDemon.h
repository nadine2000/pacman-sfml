#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.h"
#include "GameObject.h"
#include "DemonBase.h"

constexpr auto SMART_DEMON_SPEED = 250.0f;


class SmartDemon : public DemonBase
{

public:

	SmartDemon(sf::Vector2f, sf::Vector2f, GameTexture_t, Board&);
	void move(const float, sf::Vector2f) override;
	

private:

	Board& m_board;

    sf::Vector2f BFS(sf::Vector2f pacman);


};