#include "Brick.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Brick::Brick(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor) : GameObject(bType, fX, fY, fSizeL, fSizeH, cColor)
{
	m_iHp = 2;
	m_iMaxHp = 2; 
}