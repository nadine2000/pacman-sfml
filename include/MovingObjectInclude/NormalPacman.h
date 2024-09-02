#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "PacmanBase.h"

class DemonBase;
class StaicObject;

constexpr auto NORMAL_PACMAN_SPEED = 500.0f;

class NormalPacman : public PacmanBase
{

public:

	using PacmanBase::PacmanBase;

	void collisonWith(Controller&, Gift&) override;
	void collisonWith(Controller&, Wall&) override;
	void collisonWith(Controller&, Empty&) override;
	void collisonWith(Controller&, Cookie&) override;
	void collisonWith(Controller&, Key&) override;
	void collisonWith(Controller&, Door&) override;
	void collisonWith(Controller&, StaticObject&) override;

};

