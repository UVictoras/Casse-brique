// Casse brique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include "GameManager.h"

int main()
{
    GameManager::Initialize();

    GameManager::Get()->GameLoop();

    return 0;
}