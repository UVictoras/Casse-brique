#include "Canon.h"
#include "Math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Canon::Canon(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor) : GameObject(bType, fX, fY, fSizeL, fSizeH, cColor)
{
	orientation = 0;
}

void Canon::Rotate(float vLocalPositionX, float vLocalPositionY)
{
	if (vLocalPositionY < m_fY)
	{
		m_sGraphism->setOrigin(m_fSizeL / 2, 0);
		orientation = Math::Rotate(this, vLocalPositionX, vLocalPositionY);
		m_sGraphism->setRotation(orientation);
	}
}
