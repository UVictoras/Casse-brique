#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Brick.h"
#include "Canon.h"
#include "Ball.h"

typedef void(*func)();
using namespace std;

class EventManager
{
private:
	static EventManager* eInstance;

public:
	static void Initialize()
	{
		EventManager::eInstance = new EventManager();
	}

	static EventManager* Get()
	{
		return eInstace;
	}

public:
	map<sf::Event::EventType, map<sf::Mouse::Button, func>> m_cMap;

	void AddComponent(sf::Event::EventType eventType, sf::Mouse::Button mouseEvent, func* event);

	EventManager();

	EventManager(func* event);

	void Update(sf::RenderWindow* oWindow);

	void ManageEvent(sf::Event::EventType eType, sf::Mouse::Button mousePressed);
};
