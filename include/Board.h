#pragma once
#include <thread>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Board.h"
#include "StaticObjectInclude/StaticObject.h"
#include <queue>



class Board
{

public:

	Board();
	void readFile();
	int countChar(const char character);
    sf::Vector2i getLocation(const char character);
	bool lastCookie();
    void createStaticObject(const char, int , int);
	void makeObjectFromFile();
	void drawStatic(sf::RenderWindow& window);
	std::vector <std::unique_ptr<DemonBase>> createDemons();
	std::unique_ptr<StaticObject>& getStaticObject(const sf::Vector2i index);
	sf::Vector2i getIndex(const sf::Vector2f& position);
	void emptyObject(const sf::Vector2i index);
	void searchDoor(const sf::Vector2i index);
	sf::Vector2f objectPosition(const sf::Vector2i index);
	sf::Vector2f getSpriteSize() const;
	int getLevel() const;
	void readSameLevel();
	void initialize();
	int getRow() const;
	int getCol() const;
	bool validIndex(int,int);
	bool validMove(const sf::Vector2i index);
	bool lastLevel();

private:

	std::vector<std::unique_ptr<StaticObject>> m_staticBoard;

	std::vector <std::string> m_board;
	
	unsigned int m_level = 0,
		m_cookies = 0,
		m_heigh = 1, m_tolalLevels = 0;

	int m_row = 0,
		m_col = 0;

	sf::Vector2f m_spriteSize;
};
