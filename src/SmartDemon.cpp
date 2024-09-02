#include "MovingObjectInclude/SmartDemon.h"
#include <iostream>
#include "AllInclude.h"
#include <cmath>


SmartDemon::SmartDemon(sf::Vector2f position, sf::Vector2f size, GameTexture_t obj, Board& board)
    : DemonBase(position, size, obj), m_board(board)
{
    m_sprite.setColor(sf::Color::Blue);
}

void SmartDemon::move(const float time, sf::Vector2f pacman)
{
    sf::Vector2f goTo = BFS(pacman);
    sf::Vector2i nextStep = m_board.getIndex(m_sprite.getPosition()) + (sf::Vector2i)goTo;
    sf::Vector2f nextPos = m_board.objectPosition(nextStep);
    sf::Vector2f diff = (nextPos - m_sprite.getPosition());

    if (abs(diff.x) <= 1 && abs(diff.y) <= 1)
    {
        m_sprite.setPosition(nextPos);
    }
    else
    {
        m_newPosition = goTo * time * SMART_DEMON_SPEED;
        m_sprite.move(m_newPosition);
        m_position = m_sprite.getPosition();
        if (!validPostion())
            m_sprite.move(-m_newPosition);
    }
}

sf::Vector2f SmartDemon::BFS(sf::Vector2f pacman)
{
    Point src = { m_board.getIndex(m_sprite.getPosition()).x, m_board.getIndex(m_sprite.getPosition()).y , std::vector<sf::Vector2f>() };
    Point dest = { m_board.getIndex(pacman).x, m_board.getIndex(pacman).y , std::vector<sf::Vector2f>() };
    
    if (src.y == dest.y && src.x == dest.x)
         return STAY;

    std::vector<std::vector<bool>> visited(m_board.getRow(), std::vector<bool>(m_board.getCol(), false));
    std::queue<queueNode> q;

    queueNode s = { src, STAY };
   
    q.push(s);

    visited[src.y][src.x] = true;

    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        q.pop();

        if (pt.x == dest.x && pt.y == dest.y)
        {
            curr.pt.path.push_back(curr.dir);

            if (curr.pt.path.size() >= 1)
                return curr.pt.path[1];
        }

        for (int i = 0; i < TOTAL_DIRECTION; i++)
        {
            int row = pt.y + (int)DIRECTION[i].y;
            int col = pt.x + (int)DIRECTION[i].x;

            if (m_board.validIndex(col, row) && m_board.validMove({col,row}) && !visited[row][col])
            {
                visited[row][col] = true;

                queueNode Adjcell = { {col, row}, DIRECTION[i] };

                Adjcell.pt.path = curr.pt.path;
                Adjcell.pt.path.push_back(curr.dir);
               
                q.push(Adjcell);
            }
        }
    }

    return STAY;
}