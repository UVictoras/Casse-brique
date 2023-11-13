#include "GameManager.h"
#include "Math.h"
#include <iostream>

sf::Event pressed;

GameManager* GameManager::pInstance = nullptr;

Ball* CreateBall(Canon* Canon)
{
	Ball* Balls = new Ball(Canon->m_fX, Canon->m_fY + Canon->m_fSizeL/2, 25.f, 0.f, sf::Color::Green);
    Balls->m_fMovement = Canon->m_fDirection;
    Math::Normalize(&Balls->m_fMovement.x, &Balls->m_fMovement.y);
    
    return Balls;
}

void EventShoot() 
{
    GameManager::Get()->Shoot();
}

void GameManager::Shoot() 
{


}

GameManager::GameManager()
{


}

void GameManager::GameLoop(sf::RenderWindow* oWindow)
{
    std::vector<GameObject*> m_oBalls;

    Canon Rectangle(true, 960.f, 540.f, 50.f, 50.f, sf::Color::Blue);

    //m_oBalls.push_back(CreateBall(&Rectangle));

    sf::Clock oClock;
    float fDeltaTime = 0;
    //GameLoop
    while (oWindow->isOpen())
    {
        //EVENT
        EventManager::Get()->Update(oWindow);

       /*
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
        }*/

        sf::Vector2i localPosition = sf::Mouse::getPosition(*oWindow);

        //DRAW
        oWindow->clear();

        if (pressed.type)
        {
            eEventManager->ManageEvent(pressed.type, pressed.mouseButton.button);
        }
        /*
        Circle.Draw(oWindow);
        Circle.Move(fDeltaTime);*/
        Rectangle.Draw(oWindow);
        Rectangle.Rotate(localPosition.x, localPosition.y);

        oWindow->display();
        fDeltaTime = oClock.restart().asSeconds();
    }
}