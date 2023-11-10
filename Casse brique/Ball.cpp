#include "Ball.h"
#include "Math.h"
#include <SFML/Graphics.hpp>

Ball::Ball(float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor) : GameObject(false, fX, fY, fSizeL, fSizeH, cColor)
{
	m_fMovement.x = 10.f;
	m_fMovement.y = -5.f;
	Math::Normalize(&m_fMovement.x, &m_fMovement.y);
}
void Ball::Move(float fDeltaTime)
{
	m_fX += m_fDirection.x * fDeltaTime * 10.f;
	m_fY += m_fDirection.y * fDeltaTime * 10.f;
	m_sGraphism->setPosition(m_fX, m_fY);
}
void Ball::CollidObject(GameObject* Object)
{
	if (m_fX < Object->m_fX + Object->m_fSizeL)
	{
		m_fMovement.x = -m_fMovement.x;
	}
	else if (m_fX + m_fSizeL > Object->m_fX)
	{
		m_fMovement.x = -m_fMovement.x;
	}
	else if (m_fX < Object->m_fY + Object->m_fSizeH)
	{
		m_fMovement.y = -m_fMovement.y;
	}
	else if (m_fY + m_fSizeL > Object->m_fY)
	{
		m_fMovement.y = -m_fMovement.y;
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