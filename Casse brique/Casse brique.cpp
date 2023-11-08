// Casse brique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

int main()
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(1920, 1080), "SFML");

    GameObject Circle(false, 660.f, 540.f, 50.f, 0.f, sf::Color::Red);

    GameObject Rectangle(true, 960.f, 540.f, 50.f, 50.f, sf::Color::Blue);

    sf::Clock oClock;
    float fDeltaTime = 0;
    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }
        if (Circle.m_sGraphism->getGlobalBounds().intersects(Rectangle.m_sGraphism->getGlobalBounds())) {
            Circle.CollidObject(Rectangle);
        }
        if (Circle.m_fX < 0)
        {
            Circle.CollidWalls('L');
        }
        if (Circle.m_fX + Circle.m_fSizeL*2 > 1920)
        {
            Circle.CollidWalls('R');
        }
        if (Circle.m_fY < 0)
        {
            Circle.CollidWalls('T');
        }

		sf::Vector2i localPosition = sf::Mouse::getPosition(oWindow);

        //DRAW
        oWindow.clear();

        Circle.Draw(&oWindow);
        Circle.Move(fDeltaTime);
        Rectangle.Draw(&oWindow);
        Rectangle.Rotate(localPosition.x, localPosition.y);

        oWindow.display();
        fDeltaTime = oClock.restart().asSeconds();
    }

    return 0;
}