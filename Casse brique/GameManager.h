#pragma once
#include "EventManager.h"

typedef void(*func)();
using namespace std;

void CreateBall();

void EventShoot();

class GameManager
{
private:
	static GameManager* pInstance;

	Canon* oCanon;

	std::vector<Ball*> m_oBalls;

	sf::Vector2i localPosition;

	sf::RenderWindow oWindow;

public:

	static void Initialize()  
	{
		GameManager::pInstance = new GameManager();
	}

	static GameManager* Get() 
	{
		return pInstance;
	}

public:
	EventManager* eEventManager;

	GameManager();

	void GameLoop();

	//Events

	void CreateBall();

	void CloseWindow();
};