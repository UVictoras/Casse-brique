// Casse brique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include "GameManager.h"

int main()
{

    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(1920, 1080), "Casse-Brique");

    GameManager mGameManager;
    mGameManager.GameLoop(&oWindow);

    return 0;
}