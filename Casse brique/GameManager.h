#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "GameObject.h"

typedef GameObject(*func)(GameObject* Canon);
using namespace std;

GameObject Shoot(GameObject* Canon);

class GameManager
{
public:
	map<sf::Event::EventType, map<sf::Mouse::Button, func>> m_cMap;

	void AddComponent(sf::Event::EventType eventType, sf::Mouse::Button mouseEvent, func event);

	GameManager();

	GameObject EventManager(sf::Event::EventType eType, sf::Mouse::Button mousePressed, GameObject* Canon);

	void GameLoop(sf::RenderWindow* oWindow);
};