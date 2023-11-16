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

	sf::Vector2i vLocalPosition;

	sf::RenderWindow oWindow;

	bool bWon, bLost, bCanShoot;

	int iRemainingBalls;

	GameObject* sLeftSquare;
	GameObject* sRightSquare;

	sf::Font fFont;
	sf::Text tText;

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
	sf::Texture tBackground, tCanon, tBrick, tBrokenBrick, tBall, tWin, tLose;
	GameObject* sBackground;

	GameManager();

	void CheckWin();

	void CheckLose();

	void DeleteEmptyBricks();

	void SetBricksTexture();

	void GameLoop();

	//Events

	void CreateBall();

	void CloseWindow();
};