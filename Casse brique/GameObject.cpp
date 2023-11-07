#include "GameObject.h"
#include "Math.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor)
{
	m_fDirection.x = 10.f;
	m_fDirection.y = 10.f;
	Math::Normalize(&m_fDirection.x, &m_fDirection.y);

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

void GameObject::Move(float fDeltaTime)
{
	m_fX += m_fDirection.x * fDeltaTime * 10.f;
	m_fY += m_fDirection.y * fDeltaTime * 10.f;
	m_sGraphism->setPosition(m_fX, m_fY);
}
void GameObject::Rotate(float vLocalPositionX, float vLocalPositionY)
{
	if ( vLocalPositionY < m_fY)
	{
		m_sGraphism->setOrigin(m_fSizeL/2, 0);
		float mouseAngle = -atan2(vLocalPositionX - m_fX, vLocalPositionY - m_fY) * 180 / 3.14159;
		m_sGraphism->setRotation(mouseAngle);
	}
}