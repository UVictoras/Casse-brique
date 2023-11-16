#include "FileManager.h"

FileManager::FileManager()
{

}

/*
-----------------------------------------------------------------------
|   Following are the methods corresponding to the FileManager Class  |
-----------------------------------------------------------------------
*/

void FileManager::CreateLevel(const char* cFileName, vector<Brick*>* m_oBricks)
{
	m_fFichier.open(cFileName, ios::in);
	//Brick nBrick(true, 960.f, 540.f, 75.f, 50.f, sf::Color::Blue);
	if (m_fFichier)
	{
		string sLine;
		int l = 0;
		for (int j = 0; j < 8; j++)
		{
			getline(m_fFichier, sLine);
			for (int i = 0; i < sLine.size(); i++)
			{
				if (sLine[i] == 'b') {
					Brick* bBrick = new Brick(true, (600.f + (l * 85.f)) - ((l / 8) * 85.f) * 8, 35.f + ((l / 8) * 85.f), 75.f, 50.f, sf::Color::White);
					m_oBricks->push_back(bBrick);
					l += 1;
				}
				else if (sLine[i] == 'n') {
					
					l += 1;
				}
			}
		}
		m_fFichier.close();
	}
	else {
		cerr << "Impossible d'ouvrir le fichier" << endl;
	}
}
