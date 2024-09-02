#include "Controller.h"
#include "Resources.h"
#include <thread>
#include <chrono>

Controller::Controller()
{
    m_sprite[0].setTexture(Resources::instance().getTexture(MainBackground));
    m_sprite[1].setTexture(Resources::instance().getTexture(Win));
    m_sprite[2].setTexture(Resources::instance().getTexture(Lose));
    m_sprite[3].setTexture(Resources::instance().getTexture(Timeup));
    m_music.openFromFile("music.wav");
    m_music.setLoop(true);
}

void Controller::startGame()
{
	 m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT + INFORMATION), "SuperPacman");
     m_music.play();
     
     m_menu.showMenu(m_window);
     newLevel();
     
     while (m_window.isOpen())
     {
         auto event = sf::Event();
         while ( m_window.pollEvent(event) )
         {
             switch (event.type)
             {
             case sf::Event::Closed:
                 m_window.close();
                 break;
             case sf::Event::KeyPressed:
             {
                 if (event.key.code == sf::Keyboard::Escape)
                     m_window.close();
                 break;
             }
             }
         }
         mainLoop();
         draw();
     }
}

void Controller::mainLoop()
{
    if (m_lose)
    {
        m_menu.showMenu(m_window);
        m_board.initialize();
        m_lose = false;
        newLevel();
    }

    if (m_gameData.timerFinished())
    {
        Resources::instance().getSound(Sound_t::TimeEnd).play();
        m_board.readSameLevel();
        drawSprite(3);
        newLevel();
    }

    sf::Time delta = m_gameClock.restart();
    movePlayer(delta);
    moveDemons(delta);
}

void Controller::movePlayer(const sf::Time delta)
{
    moveObjectAndCheckCollision(*m_player, delta);

    if (m_takeGift)
    {
        makeSuperPacman(m_player->getPostion());
        m_takeGift = false;
    }

    if (m_super && m_superPacmanclock.getElapsedTime().asSeconds() >= 10)
        makePacman(m_player->getPostion());

    if (m_board.lastCookie())
        winGame();
}

void Controller::drawSprite(int i)
{
    m_window.clear();
    m_window.draw(m_sprite[i]);
    m_window.display();

    std::this_thread::sleep_for(std::chrono::seconds(3));

}

void Controller::winGame()
{
    Resources::instance().getSound(Sound_t::WinGame).play();

    addPoints(NEW_LEVEL_POINTS +
        (int)m_demons.size() * GHOST_POINTS);
      drawSprite(1);
      if (!m_board.lastLevel())
          newLevel();
      else
          m_lose = true;

  
}

void Controller::moveDemons(const sf::Time delta)
{
    if (!m_freezeDemon)
    {

        for (int i = 0; i < m_demons.size(); i++)
        {
            moveObjectAndCheckCollision(*m_demons[i], delta);

            if (!m_super && m_player->collisonWith(*m_demons[i]))
            {
                lostGame();
                m_player->setPosition(m_playerPos);
                for (int j = 0; j < m_demons.size(); j++)
                    m_demons[j]->goToFirstPosition();

                break;
            }
        
        }
    }
 
    if (m_freezeClock.getElapsedTime().asSeconds() >= 10)
        m_freezeDemon = false;
}

void Controller::moveObjectAndCheckCollision(MovingObject& moving, const sf::Time delta)
{
    moving.update(delta,m_player->getPostion());
    moving.cheackCollisionWithStatic(*this);
}

void Controller::draw()
{
    m_window.clear();

    m_window.draw(m_sprite[0]);

    m_board.drawStatic(m_window);
 
    for (int i = 0; i < m_demons.size(); i++)
        m_demons[i]->draw(m_window);

    m_gameData.drawGameData(m_window, m_board.getLevel(),m_points,m_life);

    m_player->draw(m_window);

    m_window.display();
} 

void Controller::newLevel()
{
    m_lose = false;
    m_super = false;
    m_takeGift = false;
    m_life = 3;

    m_board.makeObjectFromFile();
    m_playerPos = m_board.objectPosition(m_board.getLocation('a'));
    makePacman(m_playerPos);

    m_demons.clear();
    m_demons = m_board.createDemons();

    m_gameData.startTimer();
    
    m_gameClock.restart();

}

Board& Controller::getBoard() 
{
    return m_board;
}

void Controller::makePacman(sf::Vector2f pos)
{

    m_player = std::make_unique<NormalPacman>(pos,
        m_board.getSpriteSize(),
        PacmanObj);

    m_super = false;
}

void Controller::makeSuperPacman(sf::Vector2f pos)
{
    m_player = std::make_unique<SuperPacman>(pos,
        m_board.getSpriteSize(),
        SuperpacmanObj);

    m_super = true;
    m_superPacmanclock.restart();
}

void Controller::becomeSuper()
{
    m_takeGift = true;
}

void Controller::addPoints(int add)
{ 
    m_points += add;
}

void Controller::lostGame()
{
    m_life--;
    Resources::instance().getSound(Sound_t::LostLife).play();
  
    if (m_life == 0)
    {
        Resources::instance().getSound(Sound_t::LoseGame).play();
        drawSprite(2);
        m_lose = true;
        m_points = 0;
    }
}

void Controller::addLife()
{
    m_life++;
}

void Controller::freezeDemon()
{
    m_freezeDemon = true;
    m_freezeClock.restart();
}

void Controller::addTime()
{
    m_gameData.addTime();
}