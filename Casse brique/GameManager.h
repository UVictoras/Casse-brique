#pragma once
#include "EventManager.h"

typedef void(*func)();
using namespace std;

GameObject* CreateBall(GameObject* Canon);

void EventShoot();

class GameManager
{
private:
	static GameManager* pInstance;

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

	void GameLoop(sf::RenderWindow* oWindow);

	void Shoot();

};