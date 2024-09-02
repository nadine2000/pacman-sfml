#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.h"
#include "MovingObject.h"
#include "NormalPacman.h"

class StaicObject;


class DemonBase : public MovingObject
{
public:

	DemonBase(sf::Vector2f position, sf::Vector2f size, GameTexture_t obj);

	void collisonWith(Controller&, Gift&) override;
	void collisonWith(Controller&, Wall&) override;
	void collisonWith(Controller&, Empty&) override;
	void collisonWith(Controller&, Cookie&) override;
	void collisonWith(Controller&, Key&) override;
	void collisonWith(Controller&, Door&) override;
	void collisonWith(Controller&, StaticObject&) override;

	virtual ~DemonBase() = default;
};
