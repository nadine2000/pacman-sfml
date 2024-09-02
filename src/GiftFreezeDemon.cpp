#include "StaticObjectInclude/GiftFreezeDemon.h"
#include "AllInclude.h"
#include "Global.h"

void GiftFreezeDemon::collisonWith(Controller& controller, NormalPacman& pacman)
{
	Resources::instance().getSound(Sound_t::Gift).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
	controller.freezeDemon();
}

void GiftFreezeDemon::collisonWith(Controller& controller, SuperPacman& pacman)
{
	Resources::instance().getSound(Sound_t::Gift).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
	controller.freezeDemon();
}

void GiftFreezeDemon::collisonWith(Controller&, DemonBase&)
{

}