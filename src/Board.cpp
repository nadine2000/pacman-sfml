#include "Board.h"
#include "AllInclude.h"
#include "Global.h"
#include <cstdlib>

Board::Board()
{}

void Board::makeObjectFromFile()
{
	readFile();

	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)	
			createStaticObject(m_board[i][j], i, j);
}

void Board::readFile()
{
	std::ifstream file;
	file.open("Board.txt");

	if (!file.is_open())
	{
		std::cout << "Error in opening file" << std::endl;
		exit(EXIT_FAILURE);
	}

	m_board.clear();
	m_staticBoard.clear();

	auto line = std::string();

	if (m_heigh != 1)
	{
		for (unsigned int i = 0; i < m_heigh; i++)
			std::getline(file, line);
	}
	else
		file >> m_tolalLevels;

	file >> m_row >> m_col;
	file.get();

	for (int i = 0; i < m_row; i++)
	{
		std::getline(file, line);
		m_board.push_back(line);
	}

	file.close();

	m_level++;
	m_heigh = m_row + m_heigh + 1;

	m_cookies = countChar('*');

	m_spriteSize = { ((float)WINDOW_WIDTH/m_col), ((float)WINDOW_HEIGHT/m_row)};
	
    m_staticBoard = std::vector<std::unique_ptr<StaticObject>>(m_col * m_row);
}

void Board::readSameLevel()
{
	m_level--;
	m_heigh = m_heigh - m_row - 1;
}

void Board::initialize()
{
	m_level = 0;
	m_heigh = 1;
}

std::unique_ptr<StaticObject>& Board::getStaticObject(const sf::Vector2i index)
{
	int i = index.y * m_col + index.x;
	return m_staticBoard[i];
}

sf::Vector2i Board::getIndex(const sf::Vector2f& position)
{
	return  { (int)(position.x / m_spriteSize.x),(int)(position.y / m_spriteSize.y) };
}

bool Board::validIndex(int col, int row)
{
	return (col >= 0 && col < m_col && row >= 0 && row < m_row);
}

int Board::countChar(const char character)
{
	int counter = 0;
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
			if (m_board[i][j] == character)
				counter++;
	return counter;
}

sf::Vector2i Board::getLocation(const char character)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
			if (m_board[i][j] == character)
			{
				m_board[i][j] = ' ';
				return  sf::Vector2i(j, i);
			}

	return sf::Vector2i(-1, -1);
}

bool Board::lastCookie()
{
	return (m_cookies == 0);
}

void Board::searchDoor(const sf::Vector2i index)
{ 
	emptyObject(index);
	emptyObject(getLocation('D'));
}

void Board::emptyObject(const sf::Vector2i index)
{
	if (index.x != -1 && index.y != -1)
	{
		int indexz = index.y * m_col + index.x;
		if (m_board[index.y][index.x] == '*')
			m_cookies--;
		m_staticBoard[indexz] = (std::make_unique<Empty>(objectPosition({ index.x, index.y }), m_spriteSize, EmptyObj));
	}
}

void Board::createStaticObject(const char obj, int i, int j)
{
	int index = i * m_col + j;
	switch (obj)
	{
	case '#':
		m_staticBoard[index] = (std::make_unique<Wall>(objectPosition({ j, i }), m_spriteSize, WallObj));
		break;
	case '*':
		m_staticBoard[index] = (std::make_unique<Cookie>(objectPosition({ j, i }), m_spriteSize, CookieObj));
		break;
	case 'D':
		m_staticBoard[index] = (std::make_unique<Door>(objectPosition({ j, i }), m_spriteSize, DoorObj));
		break;
	case '%':
		m_staticBoard[index] = (std::make_unique<Key>(objectPosition({ j, i }), m_spriteSize, KeyObj));
		break;
	case '$':
		m_staticBoard[index] = (std::make_unique<GiftBecomeSuperPacman>(objectPosition({ j, i }), m_spriteSize, GiftObj));
		break;
	case '-':
		m_staticBoard[index] = (std::make_unique<GiftAddPacmanLife>(objectPosition({ j, i }), m_spriteSize,GiftAddLifeObj));
		break;
	case '+':
		m_staticBoard[index] = (std::make_unique<GiftAddTime>(objectPosition({ j, i }), m_spriteSize, GiftAddTimeObj));
		break;
	case '=':
		m_staticBoard[index] = (std::make_unique<GiftFreezeDemon>(objectPosition({ j, i }), m_spriteSize, GiftFreezeDemonObj));
		break;
	default:
		m_staticBoard[index] = (std::make_unique<Empty>(objectPosition({ j, i }), m_spriteSize, EmptyObj));
			break;
	}
}

void Board::drawStatic(sf::RenderWindow& window)
{
	for (int i = 0; i < m_col * m_row; i++)
		m_staticBoard[i]->draw(window);
}

std::vector <std::unique_ptr<DemonBase>> Board::createDemons()
{
	std::vector <std::unique_ptr<DemonBase>> enemy(countChar('&') + countChar('^'));
	int index = 0;

	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
		{
			 if (m_board[i][j] == '&')
			 {
				 enemy[index] = std::make_unique<RandomDemon>(objectPosition({ j, i }), m_spriteSize, DemonObj);
				 index++;
			 }

			 if (m_board[i][j] == '^')
			 {
				 enemy[index] = std::make_unique<SmartDemon>(objectPosition({ j, i }), m_spriteSize, Smart, *this);
				 index++;
			 }
		}

	return enemy;
}

sf::Vector2f Board::objectPosition(const sf::Vector2i index)
{
	return { (m_spriteSize.x * index.x), (m_spriteSize.y * index.y) };
}

sf::Vector2f Board::getSpriteSize() const 
{
	return m_spriteSize;
}

int Board::getLevel() const
{
	return m_level;
}

int Board::getRow() const
{
	return m_row;
}
int Board::getCol() const
{
	return m_col;
}

bool Board::validMove(const sf::Vector2i index)
{
	return (m_board[index.y][index.x] != '#' && m_board[index.y][index.x] != 'D');
}

bool Board::lastLevel()
{
	return (m_level  == m_tolalLevels);
} 