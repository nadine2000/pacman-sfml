#include "MovingObjectInclude/DemonBase.h"
#include "AllInclude.h"


DemonBase::DemonBase(sf::Vector2f position, sf::Vector2f size, GameTexture_t obj) : MovingObject(position, size, obj)
{
    m_sprite.setTexture(Resources::instance().spriteSheet());
    m_sprite.setScale(((size.x - 20) * (25) / m_sprite.getTexture()->getSize().x), ((size.y - 20) * (25) / m_sprite.getTexture()->getSize().y));
    update();
}

void DemonBase::collisonWith(Controller& controller, Gift& obj)
{
    obj.collisonWith(controller, *this);
}

void DemonBase::collisonWith(Controller& controller, Wall& obj)
{
    obj.collisonWith(controller, *this);
}

void DemonBase::collisonWith(Controller& controller, Empty& obj)
{
    obj.collisonWith(controller, *this);
}

void DemonBase::collisonWith(Controller& controller, Cookie& obj)
{
    obj.collisonWith(controller, *this);
}

void DemonBase::collisonWith(Controller& controller, Key& obj)
{
    obj.collisonWith(controller, *this);
}

void DemonBase::collisonWith(Controller& controller, Door& obj)
{
    obj.collisonWith(controller, *this);
}

void DemonBase::collisonWith(Controller& controller, StaticObject& obj)
{
    obj.collisonWith(controller, *this);
}