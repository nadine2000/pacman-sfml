#include "GameObject.h"
#include "Resources.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, GameTexture_t obj)
	: m_position(position)
{
	m_sprite.setPosition(position);

	if (obj != PacmanObj && obj != SuperpacmanObj && obj != Smart && obj != DemonObj)
	{
		m_sprite.setTexture(Resources::instance().getTexture(obj));
		m_sprite.setScale(((size.x-10) / TEXTURE_WIDTH), ((size.y-10) / TEXTURE_WIDTH));
	}	
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::Sprite GameObject::getSprite() const
{
	return m_sprite;
}