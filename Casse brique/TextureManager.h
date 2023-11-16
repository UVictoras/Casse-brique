#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager();

	void CreateTexture(const char* cImageName, sf::Texture* tTexture);
};