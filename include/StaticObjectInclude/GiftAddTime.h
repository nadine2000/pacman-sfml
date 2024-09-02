#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "StaticObjectInclude/Gift.h"

class GiftAddTime : public Gift
{

public:

	using Gift::Gift;

	void collisonWith(Controller&, NormalPacman&) override;
	void collisonWith(Controller&, SuperPacman&) override;
	void collisonWith(Controller&, DemonBase&) override;
};