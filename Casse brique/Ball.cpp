#include "Ball.h"
#include "Math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Ball::Ball(float fX, float fY, float fSizeL, float fSizeH, float fDirectionX, float fDirectionY, sf::Color cColor) : GameObject(false, fX, fY, fSizeL, fSizeH, cColor)
{
	m_fMovement.x = fDirectionX;
	m_fMovement.y = fDirectionY;
	fSpeed = 50;
	Math::Normalize(&m_fMovement.x, &m_fMovement.y);
}

void Ball::Move(float fDeltaTime)
{
	m_fX += m_fMovement.x * fDeltaTime * 10.f * fSpeed;
	m_fY += m_fMovement.y * fDeltaTime * 10.f * fSpeed;
	m_sGraphism->setPosition(m_fX, m_fY);
}

bool IsInsideInterval(int v, int vMin, int vMax)
{
	return v >= vMin && v <= vMax;
}

void Ball::CollidObject(Brick* Object)
{
	bool Bot = IsInsideInterval(m_fY + m_fSizeH , Object->m_fY , Object->m_fY + Object->m_fSizeH );
	bool Top = IsInsideInterval(m_fY, Object->m_fY , Object->m_fY + Object->m_fSizeH );
	bool Right = IsInsideInterval(m_fX, Object->m_fX, Object->m_fX + Object->m_fSizeL);
	bool Left = IsInsideInterval(m_fX + m_fSizeH, Object->m_fX, Object->m_fX + Object->m_fSizeL);

	if (Top or Bot) 
	{
		m_fMovement.y = -m_fMovement.y;
		Object->Hit();
		return;
	}

	if (Right or Left)
	{
		m_fMovement.x = -m_fMovement.x;
		Object->Hit();
		return;
	}
}

void Ball::CollidWalls(char cMovement)
{ // L for Left; R for Right; T for Top
	if (cMovement == 'L' || cMovement == 'R')
	{
		m_fMovement.x = -m_fMovement.x;
	}
	else if (cMovement == 'T')
	{
		m_fMovement.y = -m_fMovement.y;
	}
}

void Ball::SetDirection(sf::Vector2i localPosition)
{
	float fTempX, fTempY;
	fTempX = localPosition.x - m_fX;
	fTempY = localPosition.y - m_fY;
	Math::Normalize(&fTempX, &fTempY);
	m_fMovement.x = fTempX;
	m_fMovement.y = fTempY;
}