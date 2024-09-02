#include "StaticObjectInclude/GiftAddTime.h"
#include "AllInclude.h"
#include "Global.h"


void GiftAddTime::collisonWith(Controller& controller, NormalPacman& pacman)
{
	Resources::instance().getSound(Sound_t::Gift).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
	controller.addTime();
}

void GiftAddTime::collisonWith(Controller& controller, SuperPacman& pacman)
{
	Resources::instance().getSound(Sound_t::Gift).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
	controller.addTime();
}

void GiftAddTime::collisonWith(Controller&, DemonBase&)
{

}