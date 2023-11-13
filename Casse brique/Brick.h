#pragma once
#include "GameObject.h"
class Brick : public GameObject
{
private:
	int m_iHp;
	int m_iMaxHp;
public:
	Brick(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);


};

