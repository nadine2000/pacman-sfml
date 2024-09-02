#include "MovingObjectInclude/MovingObject.h"
#include "AllInclude.h"

const auto AnimationTime = sf::seconds(0.3f);

MovingObject::MovingObject(sf::Vector2f position, sf::Vector2f size , GameTexture_t obj)
    : m_data(Resources::instance().animationData(obj)), GameObject(position, size,obj)
{
    m_firstPosition = m_newPosition = position;
}

sf::Vector2f MovingObject::getPostion() const
{
    return m_sprite.getPosition();
}

void MovingObject::goToFirstPosition()
{
    m_position = m_firstPosition;
    m_sprite.setPosition(m_firstPosition);
}

void MovingObject::setEatenCell(sf::Vector2i i)
{
    m_eat = i;
}

sf::Vector2i MovingObject::getEatenCell()
{
    return m_eat; 
}

void MovingObject::cheackCollisionWithStatic(Controller& controller)
{
    sf::Vector2i startIndex = controller.getBoard().getIndex(getPostion());

    int i = 0;

    for (int r = startIndex.y; i < 2 &&  r < controller.getBoard().getRow(); r++)
    {
        int j = 0;

        for (int c = startIndex.x; j < 2 && controller.getBoard().getRow(); c++)
        {
            auto object = controller.getBoard().getStaticObject({c,r}).get();
            if (collided(object->getSprite()))
            {    
                setEatenCell({ c,r });
                collisonWith(controller, *object);
            }
            j++;
        }
        i++;
    }
}

bool MovingObject::collided(sf::Sprite otherObj)
{
    return m_sprite.getGlobalBounds().intersects(otherObj.getGlobalBounds());
}

void MovingObject::pushBack()
{
    m_sprite.move(-m_newPosition);
}

bool MovingObject::validPostion()
{
    return (m_position.x >= 0 && m_position.y >= 0 && 
        m_position.x <= (WINDOW_WIDTH - m_sprite.getScale().x * m_sprite.getTexture()->getSize().x / 25) &&
       m_position.y <= (WINDOW_HEIGHT- m_sprite.getScale().y * m_sprite.getTexture()->getSize().y / 25));
}

bool MovingObject::collisonWith(MovingObject& demon) 
{
    return collided(demon.getSprite());
}

void MovingObject::direction(Direction dir)
{
    if (m_dir1 == dir || dir == Direction::Stay)
        return;

    m_dir1 = dir;
    update();
}

void MovingObject::update(sf::Time delta, sf::Vector2f pacman)
{
    move(delta.asSeconds(), pacman);

    m_elapsed += delta;

    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir1)->second.size();
        update();
    }
}

void MovingObject::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir1)->second[m_index]);
}
