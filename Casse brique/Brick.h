#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class Brick : public GameObject
{
private:
	int m_iMaxHp;
public:
	int m_iHp;

	Brick(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);

	void Hit();
};

