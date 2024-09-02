#include "MovingObjectInclude/PacmanBase.h"
#include "AllInclude.h"

PacmanBase::PacmanBase(sf::Vector2f position, sf::Vector2f size, GameTexture_t obj):MovingObject(position, size, obj)
{ 
    if (obj == SuperpacmanObj)
        m_sprite.setColor(sf::Color::Red);
    m_sprite.setTexture(Resources::instance().spriteSheet());
    m_sprite.setScale(((size.x - 20) * (25) / m_sprite.getTexture()->getSize().x), ((size.y - 20) * (25) / m_sprite.getTexture()->getSize().y));
    update();
}

void PacmanBase::move(const float time, sf::Vector2f)
{
    m_newPosition = NORMAL_PACMAN_SPEED * time * dirFromKey();
    direction(m_dir);
    m_sprite.move(m_newPosition);
    m_position = m_sprite.getPosition();
    if (!validPostion())
        m_sprite.move(-m_newPosition);
    
}

sf::Vector2f PacmanBase::dirFromKey()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_dir = Direction::Right;
        return RIGHT;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_dir = Direction::Left;
        return LEFT;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_dir = Direction::Up;
        return UP;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_dir = Direction::Down;
        return DOWN;
    }

    m_dir = Direction::Stay;
    return sf::Vector2f(0, 0);
}

void PacmanBase::setPosition(const sf::Vector2f pos)
{
    m_position = pos;
    m_sprite.setPosition(pos);
}

