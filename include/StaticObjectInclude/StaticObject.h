#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "MovingObjectInclude/SuperPacman.h"
#include "MovingObjectInclude/NormalPacman.h"
#include "MovingObjectInclude/DemonBase.h"

class Controller;

class StaticObject : public GameObject
{

public:

	using GameObject::GameObject;

	virtual void collisonWith(Controller&, NormalPacman&) = 0;
	virtual void collisonWith(Controller&, SuperPacman&) = 0;
	virtual void collisonWith(Controller&, DemonBase&) = 0;
	void collisonWith(Controller&, StaticObject&) { };
	
	virtual ~StaticObject() = default;

};