#pragma once
#include "GameObject.h"
class Canon : public GameObject
{
public:
	float fOrientation;

	Canon(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);

	void Rotate(float vLocalPositionX, float vLocalPositionY);

	void ChangeDirection(sf::Vector2i localPosition);

};

