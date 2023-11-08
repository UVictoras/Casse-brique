#pragma once

#include <SFML/System.hpp>

namespace sf
{
	class Shape;
	class Color;
	class RenderWindow;
}

class GameObject 
{
public:
	bool m_bType;
	float m_fX, m_fY;
	float m_fSizeL, m_fSizeH;
	sf::Vector2f m_fDirection;
	sf::Shape* m_sGraphism;


	GameObject(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);

	void Draw(sf::RenderWindow* oWindow);

	void Move(float fDeltaTime);

	void Rotate(float vLocalPositionX, float vLocalPositionY);

	void CollidObject(GameObject Object);

	void CollidWalls(char cDirection);
}; 