#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.h"
#include "GameObject.h"

class Board;
class Wall;
class Empty;
class Gift;
class Cookie;
class Key;
class Door;
class StaticObject;
class Controller;

#include <unordered_map>
#include <vector>



class MovingObject : public GameObject
{

public:

	MovingObject(sf::Vector2f position = sf::Vector2f(), 
		sf::Vector2f size = sf::Vector2f(),
		GameTexture_t obj = EmptyObj);

	void cheackCollisionWithStatic(Controller&);
	sf::Vector2f getPostion() const;
	void goToFirstPosition();
	bool validPostion();
	void pushBack();
	void setEatenCell(sf::Vector2i i);
	sf::Vector2i getEatenCell();
	bool collided(sf::Sprite);
	void update(sf::Time delta, sf::Vector2f);
	bool collisonWith(MovingObject& d);

    virtual void move(const float, sf::Vector2f) = 0;
	virtual void collisonWith(Controller&, StaticObject&) = 0;
	virtual void collisonWith(Controller&, Gift&) = 0;
	virtual void collisonWith(Controller&, Wall&) = 0;
	virtual void collisonWith(Controller&, Empty&) = 0;
	virtual void collisonWith(Controller&, Cookie&) = 0;
	virtual void collisonWith(Controller&, Key&) = 0;
	virtual void collisonWith(Controller&, Door&) = 0;

	
	virtual ~MovingObject() = default;

protected:


	void direction(Direction dir);
	void update();

	sf::Vector2f m_firstPosition,
		m_newPosition;
	
	sf::Vector2i m_eat = {0,0};
	
	Direction m_dir = Direction::Up;
	const AnimationData& m_data;
	sf::Time m_elapsed = {};
	Direction m_dir1 = Direction::Up;
	int m_index = 0;
	
};

