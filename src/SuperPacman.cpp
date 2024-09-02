
#include "MovingObjectInclude/SuperPacman.h"
#include "AllInclude.h"
#include "StaticObjectInclude/StaticObject.h"

void SuperPacman::collisonWith(Controller& controller, Gift& obj)
{
    obj.collisonWith(controller, *this);
}

void SuperPacman::collisonWith(Controller& controller, Wall& obj)
{
    obj.collisonWith(controller, *this);
}

void SuperPacman::collisonWith(Controller& controller, Empty& obj)
{
    obj.collisonWith(controller, *this);
}

void SuperPacman::collisonWith(Controller& controller, Cookie& obj)
{
    obj.collisonWith(controller, *this);
}

void SuperPacman::collisonWith(Controller& controller, Key& obj)
{
    obj.collisonWith(controller, *this);
}

void SuperPacman::collisonWith(Controller& controller, Door& obj)
{
    obj.collisonWith(controller, *this);
}

void SuperPacman::collisonWith(Controller& controller, StaticObject& obj)
{
    obj.collisonWith(controller, *this);
}