#include "MovingObjectInclude/RandomDemon.h"
#include <iostream>
#include "AllInclude.h"

void RandomDemon::move(const float time, sf::Vector2f)
{
    if (m_clock.getElapsedTime().asSeconds() >= 3)
    {
        m_clock.restart();
        m_dir = static_cast<Direction>(rand() % static_cast<int>(Direction::Max));
        direction(m_dir);
    }
    
    m_newPosition = toVector(m_dir) * time * RANDOM_DEMON_SPEED;
    
    m_sprite.move(m_newPosition);
    m_position = m_sprite.getPosition();
  
    if (!validPostion())
        m_sprite.move(-m_newPosition);
}

sf::Vector2f RandomDemon::toVector(Direction dir)
{
    switch (dir)
    {
    case Direction::Up:
        return UP;
    case Direction::Down:
        return DOWN;
    case Direction::Right:
        return RIGHT;
    case Direction::Left:
        return LEFT;
    case Direction::Stay:
        return STAY;
    default:
        return { 0, 0 };
    }
}

