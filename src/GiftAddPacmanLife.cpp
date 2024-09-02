#include "StaticObjectInclude/GiftAddPacmanLife.h"
#include "AllInclude.h"
#include "Global.h"


void GiftAddPacmanLife::collisonWith(Controller& controller, NormalPacman& pacman)
{
	Resources::instance().getSound(Sound_t::Gift).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
	controller.addLife();
}

void GiftAddPacmanLife::collisonWith(Controller& controller, SuperPacman& pacman)
{
	Resources::instance().getSound(Sound_t::Gift).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
	controller.addLife();
}

void GiftAddPacmanLife::collisonWith(Controller&, DemonBase&)
{

}