#pragma once
#include "GameObject.h"
#include "Brick.h"

class Ball : public GameObject
{

public:
	sf::Vector2f m_fMovement;
	float fSpeed;

	Ball(float fX, float fY, float fSizeL, float fSizeH,float fDirectionX,float fDirectionY, sf::Color cColor);

	void Move(float fDeltaTime);

	void CollidObject(Brick* Object);

	void CollidWalls(char cMovement);

	void SetDirection(sf::Vector2i localPosition);

};