#include "Brick.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Brick::Brick(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor) : GameObject(bType, fX, fY, fSizeL, fSizeH, cColor)
{
	m_iHp = 2;
	m_iMaxHp = 2; 
}

void Brick::Hit(){
	if (m_iHp > 1){
		m_iHp -= 1;
		sf::Color Yellow;
	}
	/*else if (m_iHp == 1){
		m_iHp -= 1;
		delete this;
	}*/
}