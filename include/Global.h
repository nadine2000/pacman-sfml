#pragma once
#include <unordered_map>
#include <vector>

enum GameTexture_t
{
	WallObj,
	GiftObj,
	GiftAddTimeObj,
	GiftAddLifeObj,
	GiftFreezeDemonObj,
	DoorObj,
	KeyObj,
	CookieObj,
	EmptyObj,
	MenueBackgrond,
	MainBackground,
	Help, 
	Win,
	Lose, 
	Timeup,
	PacmanObj,
	DemonObj,
	SuperpacmanObj,
	Smart
};

enum class Direction
{
    Up,
	Left,
	Right,
    Down,  
    Stay,
    Max,
};

enum class Font_t
{
	RAVIE,
	FORTE
};

enum class Sound_t
{
	EatCookie,
	TakeKey,
	TimeEnd,
	WinGame,
	IsSuper,
	Gift,
	LostLife,
	LoseGame
};

//##################################################

struct Point
{
	int x;
	int y;
	std::vector<sf::Vector2f> path;
};

struct queueNode
{
	Point pt;
	sf::Vector2f dir;
};


const int TOTAL_DIRECTION = 4;

const sf::Vector2f UP = { 0, -1 };
const sf::Vector2f LEFT = { -1, 0 };
const sf::Vector2f RIGHT = { 1, 0 };
const sf::Vector2f DOWN = { 0, 1 };
const sf::Vector2f STAY = { 0, 0 };

const sf::Vector2f DIRECTION[TOTAL_DIRECTION] = { UP, LEFT, RIGHT, DOWN };

//##################################################

struct AnimationData
{
	using ListType = std::vector<sf::IntRect>;
	using DataType = std::unordered_map<Direction, ListType>;
	DataType m_data;
};

//##################################################

const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 900;
const int INFORMATION = 100;

//####################################3
