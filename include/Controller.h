#pragma once
#include "Board.h"
#include "Menu.h"
#include "Global.h"
#include <iostream>
#include "SFML/Audio.hpp"
#include <Windows.h>
#include "GameInformation.h"
#include "AllInclude.h"

const int CONTROLLER_SPRITE = 4;

class Controller
{

public:

	Controller();
	void startGame();
	Board& getBoard();
	void addPoints(int);
	void becomeSuper();
	void addLife();
	void freezeDemon();
	void addTime();

private:

	sf::Clock m_gameClock;
	sf::Clock  m_superPacmanclock;
	sf::Clock  m_freezeClock;

	sf::Music m_music;

	sf::Time m_passedTime;
	sf::RenderWindow m_window;
	sf::Sprite m_sprite[CONTROLLER_SPRITE];
	sf::Vector2f m_playerPos;

	Board m_board;
	Menu m_menu;
	GameInformation m_gameData;
	
	std::vector <std::unique_ptr<DemonBase>> m_demons;
	std::unique_ptr<PacmanBase> m_player;

	bool m_super = false;
	bool m_takeGift = false;
	bool m_freezeDemon = false;
	bool m_lose = false;

	int m_points = 0;
	int m_life = 3;
	
	const int GHOST_POINTS = 2;
	const int NEW_LEVEL_POINTS = 50;

	void draw();
	void newLevel();
	void moveObjectAndCheckCollision(MovingObject&, const sf::Time delta);
	void makePacman(sf::Vector2f);
	void makeSuperPacman(sf::Vector2f);
	void movePlayer(const sf::Time delta);
	void moveDemons(const sf::Time delta);
	void lostGame();
	void winGame();
	void drawSprite(int i);
	void mainLoop();
};