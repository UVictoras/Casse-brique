#pragma once
#include "GameObject.h"
class Ball : GameObject
{

public:
	sf::Vector2f m_fMovement;

	Ball(float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);

	void Move(float fDeltaTime);

	void Rotate(float vLocalPositionX, float vLocalPositionY);

	void CollidObject(GameObject* Object);

	void CollidWalls(char cMovement);

};