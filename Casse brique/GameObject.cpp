#include "GameObject.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor)
{
	m_bType = bType; // True -> Rectangle; False -> Circle
	m_fX = fX;
	m_fY = fY;
	m_fSizeH = fSizeH;
	m_fSizeL = fSizeL;
	if (m_bType)
	{
		m_sGraphism = new sf::RectangleShape(sf::Vector2f(m_fSizeL, m_fSizeH));
	}
	else
	{
		m_sGraphism = new sf::CircleShape(m_fSizeL);
	}
	m_sGraphism->setPosition(m_fX, m_fY);
	m_sGraphism->setFillColor(cColor);
}

void GameObject::Draw(sf::RenderWindow* oWindow)
{
	oWindow->draw(*m_sGraphism);
}