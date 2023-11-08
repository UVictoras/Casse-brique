#include <iostream>
#include "GameObject.h"
#include "Math.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor)
{
	m_fDirection.x = 10.f;
	m_fDirection.y = -5.f;
	//Math::Normalize(&m_fDirection.x, &m_fDirection.y);

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
	if (vLocalPositionY < m_fY)
	{
		m_sGraphism->setOrigin(m_fSizeL / 2, 0);
		float mouseAngle = Math::Rotate(this, vLocalPositionX, vLocalPositionY);
		m_sGraphism->setRotation(mouseAngle);
	}
}

bool IsInsideInterval(int v, int vMin, int vMax) 
{
	return v >= vMin && v <= vMax;
}

void GameObject::CollidObject(GameObject Object)
{
	bool bIsXMinInside  = IsInsideInterval(m_fX, Object.m_fX, Object.m_fX + Object.m_fSizeL);
	bool bIsXMaxInside = IsInsideInterval(Object.m_fX, m_fX, m_fX + m_fSizeL);
	bool bIsYMinInside = IsInsideInterval(m_fY, Object.m_fY, Object.m_fY + Object.m_fSizeH);
	bool bIsYMaxInside = IsInsideInterval(Object.m_fY, m_fY, m_fY + m_fSizeL);


	if (m_fX < Object.m_fX + Object.m_fSizeL)
	{
		m_fDirection.x = -m_fDirection.x;
	}
	else if (m_fX, m_fX + m_fSizeL > Object.m_fX)
	{
		m_fDirection.x = -m_fDirection.x;
	}
	else if (m_fX < Object.m_fY + Object.m_fSizeH)
	{
		m_fDirection.y = -m_fDirection.y;
	}
	else if (m_fY + m_fSizeL > Object.m_fY)
	{
		m_fDirection.y = -m_fDirection.y;
	}
}

void GameObject::CollidWalls(char cDirection)
{ // L for Left; R for Right; T for Top
	if (cDirection == 'L' || cDirection == 'R')
	{
		m_fDirection.x = -m_fDirection.x;
	}
	else if (cDirection == 'T')
	{
		m_fDirection.y = -m_fDirection.y;
	}
}
