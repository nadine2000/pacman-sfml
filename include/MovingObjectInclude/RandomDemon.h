#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.h"
#include "GameObject.h"
#include "DemonBase.h"

constexpr auto RANDOM_DEMON_SPEED = 500.0f;

class RandomDemon : public DemonBase
{

public:

	using DemonBase::DemonBase;

	void move(const float, sf::Vector2f) override;
	

private:

    sf::Vector2f toVector(Direction dir);
	sf::Clock  m_clock;
};