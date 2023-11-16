#include "GameManager.h"
#include "Math.h"
#include "FileManager.h"
#include "TextureManager.h"
#include <iostream>
#include <vector>

using namespace std;
sf::Event pressed;

GameManager* GameManager::pInstance = nullptr;

/*
-----------------------------------------------------------------------
|      Following are the functions used in the EventManager maps      |
-----------------------------------------------------------------------
*/

void EventCreateBall()
{
    GameManager::Get()->CreateBall();
}

void EventCloseWindow()
{
    GameManager::Get()->CloseWindow();
}

/*
-----------------------------------------------------------------------
|   Following are the methods corresponding to the GameManager Class  |
-----------------------------------------------------------------------
*/

void GameManager::CloseWindow()
{
    oWindow.close();
}

void GameManager::CreateBall() 
{
    Ball* Balls = new Ball( oCanon->m_fX + oCanon->m_fSizeL / 2 * oCanon->m_fDirection.x, oCanon->m_fY + oCanon->m_fSizeH / 2 * oCanon->m_fDirection.y, 15.f, NULL, 0, 0, sf::Color::White);
    Balls->SetDirection(vLocalPosition);
    Balls->m_sGraphism->setTexture(&tBall);

    m_oBalls.push_back(Balls);
}

GameManager::GameManager() : oWindow(sf::VideoMode(1920, 1080), "Casse-Brique") // Calling RenderWindow constructor for our game window
{
    oCanon = new Canon(true, 960.f, 1080.f, 100.f, 150.f, sf::Color::White);
    bWon = false;
    bLost = false;
    bCanShoot = true;
    iRemainingBalls = 80;
    sBackground = new GameObject(true, 0.f, 0.f, 1920.f, 1080.f, sf::Color::White);

    sLeftSquare = new GameObject(true, 0.f, 0.f, 600.f, 1080.f, sf::Color(211, 211, 211, 150));

    sRightSquare = new GameObject(true, 1270.f, 0.f, 650.f, 1080.f, sf::Color(211, 211, 211, 150));
}

void GameManager::CheckWin()
{
    if (m_oBricks.begin() == m_oBricks.end())
    {
        bWon = true;
    }
}

void GameManager::CheckLose()
{
    if (iRemainingBalls == 0)
    {
        bLost = true;
    }
}

void GameManager::DeleteEmptyBricks()
{
    for (int t = 0; t < m_oBricks.size(); t++)
    {
        if (m_oBricks[t]->m_sGraphism == nullptr || m_oBricks[t]->m_sGraphism->getFillColor() == sf::Color::Transparent)
        {
            m_oBricks.erase(m_oBricks.begin()+t);
        }
    }
}

void GameManager::SetBricksTexture()
{
    for (int g = 0; g < m_oBricks.size(); g++)
    {
        if (m_oBricks[g]->m_iHp == 2)
        {
            m_oBricks[g]->m_sGraphism->setTexture(&tBrick);
        }
        else
        {
            m_oBricks[g]->m_sGraphism->setTexture(&tBrokenBrick);
        } 
    }
}

void GameManager::GameLoop()
{
    sf::Clock oClock;
    float fDeltaTime = oClock.restart().asSeconds();
	sf::Clock clock;
	float fpsLimit = 1/120;
    float fps = 0;
    fFont.loadFromFile("font/851CHIKARA-DZUYOKU_kanaA_004.ttf");

	
	tText.setFont(fFont); 
	tText.setString("Remaining Balls :" + std::to_string(iRemainingBalls));
	tText.setCharacterSize(20);
    tText.setPosition({ 390.f, 0.f});
	

    FileManager fFileManager;
    fFileManager.CreateLevel("txt/test.txt", &m_oBricks);

    TextureManager tTextureManager;
    tTextureManager.CreateTexture("img/background.jpg", &tBackground);
    tTextureManager.CreateTexture("img/win.png", &tWin);
    tTextureManager.CreateTexture("img/defeat.png", &tLose);
    tTextureManager.CreateTexture("img/canon.png", &tCanon);
    tTextureManager.CreateTexture("img/brick.png", &tBrick);
    tTextureManager.CreateTexture("img/broken-brick.png", &tBrokenBrick);
    tTextureManager.CreateTexture("img/ball.png", &tBall);

    sBackground->m_sGraphism->setTexture(&tBackground);

    oCanon->m_sGraphism->setTexture(&tCanon);


    /*
    for (int l = 0; l < 64; l++)
    {
        Brick* bBrick = new Brick(true, (600.f + (l * 85.f)) - ((l / 8) * 85.f) * 8, 35.f + ((l / 8) * 85.f), 75.f, 50.f, sf::Color::Blue);
        m_oBricks.push_back(bBrick);
    }*/

    EventManager::Initialize();
    eEventManager->Get()->AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, &EventCreateBall);
    eEventManager->Get()->AddComponent(sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Escape, &EventCloseWindow);

    //GameLoop
    while (oWindow.isOpen() && bWon == false && bLost == false)
    {
        DeleteEmptyBricks();
        SetBricksTexture();
        //EVENT
        if (m_oBalls.size() == 0)
        {
            bCanShoot = true;
        }
        EventManager::Get()->Update(&oWindow, bCanShoot);

        if (m_oBalls.size() != 0)
        {
            for (int i = 0; i < m_oBalls.size(); i++)
            {
                for (int j = 0; j < m_oBricks.size(); j++)
                {
                    if (m_oBricks[j]->m_sGraphism != nullptr)
                    {
                        if (m_oBalls[i]->m_sGraphism->getGlobalBounds().intersects(m_oBricks[j]->m_sGraphism->getGlobalBounds())) 
                        {
                            m_oBalls[i]->CollidObject(m_oBricks[j]);
                        }
                    }  
                }
                if (m_oBalls[i]->m_fX < 600)
                {
                    m_oBalls[i]->CollidWalls('L');
                }
                if (m_oBalls[i]->m_fX + m_oBalls[i]->m_fSizeL * 2 >= 1270)
                {
                    m_oBalls[i]->CollidWalls('R');
                }
                if (m_oBalls[i]->m_fY < 0)
                {
                    m_oBalls[i]->CollidWalls('T');
                }
                if (m_oBalls[i]->m_fY >= 1080)
                {
                    m_oBalls.erase(m_oBalls.begin());
                    iRemainingBalls--;
                    tText.setString("Remaining Balls :" +  std::to_string(iRemainingBalls));
                }
            }
        }

        vLocalPosition = sf::Mouse::getPosition(oWindow);

        //DRAW
        oWindow.clear();
        sBackground->Draw(&oWindow);
        sLeftSquare->Draw(&oWindow);
        sRightSquare->Draw(&oWindow);

        for (int i = 0; i < m_oBalls.size(); i++) {
			m_oBalls[i]->Draw(&oWindow);
			m_oBalls[i]->Move(fDeltaTime);
        }
        oCanon->Draw(&oWindow);

        for (int k = 0; k < m_oBricks.size(); k++)
        {
            m_oBricks[k]->Draw(&oWindow);
        }
        oCanon->Rotate(vLocalPosition.x, vLocalPosition.y);
        oCanon->ChangeDirection(vLocalPosition);
		oWindow.draw(tText);
        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();
        if (fDeltaTime < fpsLimit)
        {
            sf::sleep(sf::seconds(fpsLimit - fDeltaTime));
            fDeltaTime += fpsLimit - fDeltaTime;
        }
        fps = 1.f / fDeltaTime;
        cout <<"fps :"<< fps <<endl;

        CheckWin();
        CheckLose();

        bCanShoot = false;
    }
    while (bWon || bLost)
    {
        oWindow.clear();
        if (bWon)
        {
            sBackground->m_sGraphism->setTexture(&tWin);
        }
        else
        {
            sBackground->m_sGraphism->setTexture(&tLose);
        }
        sBackground->Draw(&oWindow);
        oWindow.display();
        EventManager::Get()->Update(&oWindow, bCanShoot);
    }
}