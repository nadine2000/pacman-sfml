#include "StaticObjectInclude/Door.h"
#include "AllInclude.h"

void Door::collisonWith(Controller&, NormalPacman& pacman)
{
	pacman.pushBack();
}

void Door::collisonWith(Controller& controller, SuperPacman& pacman)
{
	Resources::instance().getSound(Sound_t::TakeKey).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
}

void Door::collisonWith(Controller&, DemonBase& demon)
{
	demon.pushBack();
}