#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.h"
#include "GameObject.h"
#include "PacmanBase.h"

class StaicObject;


class SuperPacman : public PacmanBase
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