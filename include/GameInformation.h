#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "iostream"
#include <sstream>

const int TOATAL_GAME_DATA = 4;
const int TEXT_SIZE = 40;
const float TOTAL_TIME = 90.f; 
const float TIME_GIFT = 10.f;

class GameInformation
{

public:

	GameInformation();
	void drawGameData(sf::RenderWindow& window, int level, int point, int life);
	void addTime();
	bool timerFinished();
	void startTimer();

private:

	float m_passedTime = TOTAL_TIME;
	sf::Clock m_timer;
	sf::Text m_dataText[TOATAL_GAME_DATA];
	std::string m_gameData[TOATAL_GAME_DATA] = {"LEVEL : ",
	                                            "POINTS : ",
	                                            "LIVES : ",
	                                            "TIME : "};

	void setTime();


};