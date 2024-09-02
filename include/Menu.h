#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "iostream"
#include "Global.h"
#include "Menu.h"

const int TOATAL_BUTTONS = 4;
const int START_BUTTONS = 3;
const std::string BUTTON_NAMES[TOATAL_BUTTONS] = {"LET'S PLAY", "NEED HELP", "EXIT", "GO BACK"};
const int CHARACTER_SIZE = 55;
const sf::Vector2f TEXT_POSITION[TOATAL_BUTTONS] = { {450,350}, {450,450}, {550,550},{100, 100} };


class Menu
{

public:

	Menu();

	void showMenu(sf::RenderWindow& window);

private:

	sf::Text m_menuText[TOATAL_BUTTONS];
	int m_selectedItem;
	bool m_in = false;	
	sf::Sprite m_backgrond;
	sf::Sprite m_help;
	
	void unhighlightText(int i);
	void highlightText(int i);
	void draw(sf::RenderWindow& window);
	void moveUpOrDawn(int direction);
	void help(sf::RenderWindow& window);
	int choosePlayButton(const sf::Vector2f& Location, sf::RenderWindow& window);
	void mouseMoved(const sf::Vector2f& Location);
	void keyPressed(sf::RenderWindow& window);

};