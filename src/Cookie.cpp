#include "StaticObjectInclude/Cookie.h"
#include "AllInclude.h"

const int M_COOKIES_POINTS = 2;

void Cookie::collisonWith(Controller& controller, NormalPacman& pacman)
{
	Resources::instance().getSound(Sound_t::EatCookie).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_COOKIES_POINTS);
}

void Cookie::collisonWith(Controller& controller, SuperPacman& pacman)
{
	Resources::instance().getSound(Sound_t::EatCookie).play();
	controller.getBoard().emptyObject(pacman.getEatenCell());
	controller.addPoints(M_COOKIES_POINTS);
}

void Cookie::collisonWith(Controller&, DemonBase&)
{

}