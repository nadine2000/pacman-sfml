#include "StaticObjectInclude/Wall.h"

void Wall::collisonWith(Controller&, NormalPacman& pacman)
{
	pacman.pushBack();
}

void Wall::collisonWith(Controller&, SuperPacman& superpacman)
{
	superpacman.pushBack();
}

void Wall::collisonWith(Controller&, DemonBase& demon)
{
	demon.pushBack();
}