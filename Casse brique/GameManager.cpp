#include "GameManager.h"
#include "Math.h"
#include <iostream>

sf::Event pressed;

GameObject Shoot(GameObject* Canon)
{
	GameObject Circle(false, Canon->m_fX, Canon->m_fY + Canon->m_fSizeL/2, 25.f, 0.f, sf::Color::Green);
    Circle.m_fDirection = Canon->m_fDirection;
    Math::Normalize(&Circle.m_fDirection.x, &Circle.m_fDirection.y);
    return Circle;
}

void GameManager::AddComponent(sf::Event::EventType eventType, sf::Mouse::Button mouseEvent, func event)
{
    m_cMap[eventType][mouseEvent] = event;
}

GameManager::GameManager()
{
    AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, &Shoot);
}

GameObject GameManager::EventManager(sf::Event::EventType eType, sf::Mouse::Button mousePressed, GameObject* Canon)
{
    if (eType  == sf::Event::MouseButtonPressed)
    {
        if (m_cMap[sf::Event::MouseButtonPressed].find(mousePressed) != m_cMap[sf::Event::MouseButtonPressed].end())
        {
            return m_cMap[sf::Event::MouseButtonPressed][mousePressed](Canon);
        }
    }
}

void GameManager::GameLoop(sf::RenderWindow* oWindow)
{
    GameObject Rectangle(true, 960.f, 540.f, 50.f, 50.f, sf::Color::Blue);

    GameObject Circle(false, 960.f, 540.f, 50.f, 50.f, sf::Color::Blue);

    sf::Clock oClock;
    float fDeltaTime = 0;
    //GameLoop
    while (oWindow->isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow->pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow->close();
        }
        if (Circle.m_sGraphism->getGlobalBounds().intersects(Rectangle.m_sGraphism->getGlobalBounds())) {
            Circle.CollidObject(&Rectangle);
        }
        if (Circle.m_fX < 0)
        {
            Circle.CollidWalls('L');
        }
        if (Circle.m_fX + Circle.m_fSizeL * 2 > 1920)
        {
            Circle.CollidWalls('R');
        }
        if (Circle.m_fY < 0)
        {
            Circle.CollidWalls('T');
        }

        sf::Vector2i localPosition = sf::Mouse::getPosition(*oWindow);

        //DRAW
        oWindow->clear();

        if (pressed.type)
        {
            Circle = EventManager(pressed.type, pressed.mouseButton.button, &Rectangle);
        }

        Circle.Draw(oWindow);
        Circle.Move(fDeltaTime);
        Rectangle.Draw(oWindow);
        Rectangle.Rotate(localPosition.x, localPosition.y);

        oWindow->display();
        fDeltaTime = oClock.restart().asSeconds();
    }
}