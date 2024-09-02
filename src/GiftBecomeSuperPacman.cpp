#include "StaticObjectInclude/GiftBecomeSuperPacman.h"
#include "AllInclude.h"
#include "Global.h"


void GiftBecomeSuperPacman::collisonWith(Controller& controller, NormalPacman& pacman)
{
	Resources::instance().getSound(Sound_t::IsSuper).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
	controller.becomeSuper();
}

void GiftBecomeSuperPacman::collisonWith(Controller& controller, SuperPacman& pacman)
{
	Resources::instance().getSound(Sound_t::IsSuper).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_GIFT_POINTS);
}

void GiftBecomeSuperPacman::collisonWith(Controller&, DemonBase&)
{

}