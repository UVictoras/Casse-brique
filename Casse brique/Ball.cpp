#include "Ball.h"
#include "Math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Ball::Ball(float fX, float fY, float fSizeL, float fSizeH, float fDirectionX, float fDirectionY, sf::Color cColor) : GameObject(false, fX, fY, fSizeL, fSizeH, cColor) //Child class from GameObject
{
	m_fMovement.x = fDirectionX;
	m_fMovement.y = fDirectionY;
	fSpeed = 50;
	Math::Normalize(&m_fMovement.x, &m_fMovement.y);
}

/*
-----------------------------------------------------------------------
|      Following are the methods corresponding to the Ball Class      |
-----------------------------------------------------------------------
*/

void Ball::Move(float fDeltaTime)
{
	m_fX += m_fMovement.x * fDeltaTime * 10.f * fSpeed;
	m_fY += m_fMovement.y * fDeltaTime * 10.f * fSpeed;
	m_sGraphism->setPosition(m_fX, m_fY);
}

void Ball::CollidObject(Brick* Object)
{
	float fSizeLR = std::min(m_fY + m_fSizeL / 2, Object->m_fY + Object->m_fSizeH / 2) - std::max(m_fY + m_fSizeL / 2, Object->m_fY + Object->m_fSizeH / 2);
	float fSizeTB = std::min(m_fX + m_fSizeL / 2, Object->m_fX + Object->m_fSizeL / 2) - std::max(m_fX + m_fSizeL / 2, Object->m_fX + Object->m_fSizeH / 2);

	if (fSizeTB>fSizeLR)
	{
		m_fMovement.y = -m_fMovement.y;
		Object->Hit();
		return;
	}

	else if (fSizeLR>fSizeTB)
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