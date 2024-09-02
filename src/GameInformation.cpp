#include "GameInformation.h"
#include "Resources.h"
#include "Global.h"

GameInformation::GameInformation()
    :m_passedTime(TOTAL_TIME)
{
    for (int i = 0; i < TOATAL_GAME_DATA; i++)
    {
        m_dataText[i].setStyle(sf::Text::Bold);
        m_dataText[i].setFont(Resources::instance().getFont(Font_t::FORTE));
        m_dataText[i].setFillColor(sf::Color::Black);
        m_dataText[i].setString(m_gameData[i]);
        m_dataText[i].setPosition(300.f * i + 100.f, WINDOW_HEIGHT);
        m_dataText[i].setCharacterSize(30);
    }
}

void GameInformation::drawGameData(sf::RenderWindow& window, int level, int point, int life)
{
    m_dataText[0].setString(m_gameData[0] + std::to_string(level));
    m_dataText[1].setString(m_gameData[1] + std::to_string(point));
    m_dataText[2].setString(m_gameData[2] + std::to_string(life));
    setTime();

    for (int i = 0; i < TOATAL_GAME_DATA; i++)
        window.draw(m_dataText[i]);

}

void GameInformation::setTime()
{
    m_passedTime -= m_timer.restart().asSeconds();

    std::string min = "0" + std::to_string((int)(m_passedTime) / 60);
    
    int sec = (int)(m_passedTime) % 60;
   
    std::string seconds;

    seconds = std::to_string(sec);

    if (sec < 10)
        seconds = "0" + seconds;

    if (!timerFinished())
        m_dataText[3].setString(m_gameData[3] + min + ":" + seconds);
}

void GameInformation::addTime()
{
    m_passedTime += TIME_GIFT;
}

bool GameInformation::timerFinished()
{
    return m_passedTime <= 0;
}

void GameInformation::startTimer()
{
    m_passedTime = TOTAL_TIME;
}
