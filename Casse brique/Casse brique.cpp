// Casse brique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

int main()
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(1920, 1080), "SFML");

    GameObject Circle(false, 960.f, 540.f, 100.f, 0.f, sf::Color::Red);

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