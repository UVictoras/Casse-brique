#include "Canon.h"
#include "Math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Canon::Canon(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor) : GameObject(bType, fX, fY, fSizeL, fSizeH, cColor) //Child class from GameObject
{
	fOrientation = 0;
}

/*
-----------------------------------------------------------------------
|      Following are the methods corresponding to the Canon Class     |
-----------------------------------------------------------------------
*/

void Canon::Rotate(float vLocalPositionX, float vLocalPositionY)
{
	if (vLocalPositionY < m_fY)
	{
		m_sGraphism->setOrigin(m_fSizeL / 2, 0);
		fOrientation = Math::Rotate(this, vLocalPositionX, vLocalPositionY);
		m_sGraphism->setRotation(fOrientation);
	}
}

void Canon::ChangeDirection(sf::Vector2i localPosition)
{
	m_fDirection.x = localPosition.x - m_fX;
	m_fDirection.y = localPosition.y - m_fY;
	Math::Normalize(&m_fDirection.x, &m_fDirection.y);
}
