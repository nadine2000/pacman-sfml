#include "StaticObjectInclude/Key.h"
#include "AllInclude.h"

const int M_KEY_POINTS = 7;

void Key::collisonWith(Controller& controller, NormalPacman& pacman)
{
	Resources::instance().getSound(Sound_t::TakeKey).play();
	controller.getBoard().searchDoor(pacman.getEatenCell());
	controller.addPoints(M_KEY_POINTS);
}

void Key::collisonWith(Controller& controller, SuperPacman& pacman)
{
	Resources::instance().getSound(Sound_t::TakeKey).play();
	controller.getBoard().searchDoor(pacman.getEatenCell());
	controller.addPoints(M_KEY_POINTS);
}

void Key::collisonWith(Controller&, DemonBase&)
{

}