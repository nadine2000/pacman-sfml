#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "StaticObject.h"


class Door : public StaticObject
{

public:

	using StaticObject::StaticObject;

	void collisonWith(Controller&, NormalPacman&) override;
	void collisonWith(Controller&, SuperPacman&) override;
	void collisonWith(Controller&, DemonBase&) override;

};