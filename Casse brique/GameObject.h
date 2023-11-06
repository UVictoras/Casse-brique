#pragma once
struct Shape;

namespace sf
{
	class Shape;
	class Color;
	class RenderWindow;
}

class GameObject 
{
public:
	bool m_bType;
	float m_fX, m_fY;
	float m_fSizeL, m_fSizeH;
	sf::Shape* m_sGraphism;


	GameObject(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);

	void Draw(sf::RenderWindow* oWindow);
}; 