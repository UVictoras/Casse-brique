#include "GameManager.h"
#include "Math.h"
#include <iostream>

sf::Event pressed;

GameManager* GameManager::pInstance = nullptr;

void EventCreateBall()
{
    GameManager::Get()->CreateBall();
}

void EventCreateBall()
{
    GameManager::Get()->CreateBall();
}

void EventCloseWindow()
{
    GameManager::Get()->CloseWindow();
}

void GameManager::CloseWindow()
{
    oWindow.close();
}

void GameManager::CreateBall() 
{
    Ball* Balls = new Ball( oCanon->m_fX + oCanon->m_fSizeL / 2 * oCanon->m_fDirection.x, oCanon->m_fY + oCanon->m_fSizeH / 2 * oCanon->m_fDirection.y, 5.f, 0.f, 0, 0, sf::Color::Green);
    Balls->SetDirection(localPosition);

    m_oBalls.push_back(Balls);
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique")
{


    oCanon = new Canon(true, 960.f, 1080.f, 50.f, 100.f, sf::Color::Magenta);
}

void GameManager::GameLoop(sf::RenderWindow* oWindow)
{
    sf::Clock oClock;
    float fDeltaTime = 0;
    Brick nBrick(true, 960.f, 540.f, 75.f, 50.f, sf::Color::Blue);
    EventManager::Initialize();
    eEventManager->Get()->AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, &EventCreateBall);

    //GameLoop
    while (oWindow->isOpen())
    {
        //EVENT
        EventManager::Get()->Update(oWindow);
        
        if (m_oBalls.size() != 0)
        {
            for (int i = 0; i < m_oBalls.size(); i++)
            {
                if (m_oBalls[i]->m_sGraphism->getGlobalBounds().intersects(nBrick.m_sGraphism->getGlobalBounds())) {
                    m_oBalls[i]->CollidObject(&nBrick);
                }
                if (m_oBalls[i]->m_fX < 0)
                {
                    m_oBalls[i]->CollidWalls('L');
                }
                if (m_oBalls[i]->m_fX + m_oBalls[i]->m_fSizeL * 2 > 1920)
                {
                    m_oBalls[i]->CollidWalls('R');
                }
                if (m_oBalls[i]->m_fY < 0)
                {
                    m_oBalls[i]->CollidWalls('T');
                }
            }
        }


        localPosition = sf::Mouse::getPosition(*oWindow);

        //DRAW
        oWindow->clear();

        if (pressed.type)
        {
            eEventManager->Get()->ManageEvent(pressed.type, pressed.mouseButton.button);
        }
        for (int i = 0; i < m_oBalls.size(); i++) {
			m_oBalls[i]->Draw(oWindow);
			m_oBalls[i]->Move(fDeltaTime);
        }
        oCanon->Draw(oWindow);
		nBrick.Draw(oWindow);
        oCanon->Rotate(localPosition.x, localPosition.y);
        oCanon->ChangeDirection(localPosition);

        oWindow->display();
        fDeltaTime = oClock.restart().asSeconds();
    }
}