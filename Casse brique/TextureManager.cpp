#include "TextureManager.h"

TextureManager::TextureManager()
{

}

void TextureManager::CreateTexture(sf::Texture* tTexture)
{

	if (!tTexture->loadFromFile("img/background.jpg"))
	{
		//Image not loaded
		return;
	}

	tTexture->setSmooth(true);
}