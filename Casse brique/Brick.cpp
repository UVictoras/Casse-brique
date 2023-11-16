#include "Brick.h"

#include <iostream>

Brick::Brick(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor) : GameObject(bType, fX, fY, fSizeL, fSizeH, cColor) //Child class from GameObject
{
	m_iHp = 2;
	m_iMaxHp = 2; 
}

/*
-----------------------------------------------------------------------
|      Following are the methods corresponding to the Brick Class     |
-----------------------------------------------------------------------
*/

void Brick::Hit(){
	if (m_iHp > 1){
		m_iHp -= 1;
	}
	else if (m_iHp == 1){
		m_iHp -= 1;
		m_sGraphism = nullptr;
	}
}