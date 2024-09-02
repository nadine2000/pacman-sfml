#include "Menu.h"
#include "Resources.h"

Menu::Menu()
{
    for (int i = 0; i < TOATAL_BUTTONS; i++)
    {
        m_menuText[i].setFont(Resources::instance().getFont(Font_t::RAVIE));
        m_menuText[i].setFillColor(sf::Color::Yellow);
        m_menuText[i].setString(BUTTON_NAMES[i]);
        m_menuText[i].setPosition(TEXT_POSITION[i]);
        m_menuText[i].setCharacterSize(CHARACTER_SIZE);
    }

    m_backgrond.setTexture(Resources::instance().getTexture(MenueBackgrond));
    m_help.setTexture(Resources::instance().getTexture(Help));
    m_selectedItem = 0;
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(m_backgrond);
    for (int i = 0; i < START_BUTTONS; i++)
        window.draw(m_menuText[i]);
}

void Menu::moveUpOrDawn(int direction)
{
    unhighlightText(m_selectedItem);
    m_selectedItem = (m_selectedItem + direction + START_BUTTONS) % START_BUTTONS;
    highlightText(m_selectedItem);
}

void Menu::highlightText(int i)
{
    m_menuText[i].setOutlineColor(sf::Color::Red);
    m_menuText[i].setOutlineThickness(6);
}

void Menu::unhighlightText(int i)
{
    m_menuText[i].setOutlineColor(sf::Color::Black);
    m_menuText[i].setOutlineThickness(4);
}

void Menu::showMenu(sf::RenderWindow& window)
{
    m_in = false;
    while (window.isOpen())
    {
        window.clear();
        draw(window);
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            sf::Vector2f Location;

            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonReleased:
            {
                Location = window.mapPixelToCoords
                ({ event.mouseButton.x, event.mouseButton.y });
                
                int choosen = choosePlayButton(Location, window);
                
                if (choosen == 0)
                    return;
                if (choosen == 1)
                    help(window);

                break;
            }
            case sf::Event::MouseMoved:
                Location = (sf::Vector2f)sf::Mouse::getPosition(window);
                mouseMoved(Location);
                break;

            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape)
                    exit(EXIT_SUCCESS);

                break;
            }
            }
        }

        if (m_in)
            break;

        keyPressed(window);

    }
}

void Menu::keyPressed(sf::RenderWindow& window)
{     
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        moveUpOrDawn(-1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        moveUpOrDawn(1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        if (m_selectedItem == 0)
            m_in = true;
        if (m_selectedItem == 2)
            window.close();
        if (m_selectedItem == 1)
            help(window);
    }
}

int Menu::choosePlayButton(const sf::Vector2f& Location, sf::RenderWindow& window)
{
    for (int i = 0; i < START_BUTTONS; i++)
    {
        if (m_menuText[i].getGlobalBounds().contains(Location))
        {
            if (i == 2)
                window.close();

            return i;
        }
    }
    
    return -1;
}

void Menu::mouseMoved(const sf::Vector2f& Location)
{
    for (int i = 0; i < TOATAL_BUTTONS; i++)
        if (m_menuText[i].getGlobalBounds().contains(Location))
            highlightText(i);
        else
            unhighlightText(i);
}

void Menu::help(sf::RenderWindow& window)
{
    bool exit = false;
    while (window.isOpen() &&  !exit)
    {
        window.clear();
        window.draw(m_help);
        window.draw(m_menuText[3]);
        window.display();
        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2f Location;

            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonReleased:
                Location = window.mapPixelToCoords
                ({ event.mouseButton.x, event.mouseButton.y });
                if (m_menuText[3].getGlobalBounds().contains(Location))
                    return;
                
            case sf::Event::MouseMoved:
                Location = (sf::Vector2f)sf::Mouse::getPosition(window);
                mouseMoved(Location);
                break;

            case sf::Event::KeyPressed:
            { 
                if (event.key.code == sf::Keyboard::Return)
                    exit = true;
                
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            break;
            }       
        }
    }
}