#pragma once
#include "EventManager.h"

typedef void(*func)();
using namespace std;

class GameManager
{
private:
	static GameManager* pInstance;

	Canon* oCanon;

	std::vector<Ball*> m_oBalls;

	sf::Vector2i localPosition;

	sf::RenderWindow oWindow;

	bool bWon, bLost, bCanShoot;

	int iRemainingBalls;

	GameObject* sLeftSquare;
	GameObject* sRightSquare;

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
	std::vector<Brick*> m_oBricks;
	sf::Texture tBackground;
	GameObject* sBackground;

	GameManager();

	void CheckWin();

	void CheckLose();

	void DeleteEmptyBricks();

	void GameLoop();

	//Events

	void CreateBall();

	void CloseWindow();
};