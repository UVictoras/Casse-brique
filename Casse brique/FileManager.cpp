#include "FileManager.h"

FileManager::FileManager()
{

}

void FileManager::CreateLevel(const char* cFileName, vector<Brick*>* m_oBricks)
{
	m_fFichier.open(cFileName, ios::in);
	//Brick nBrick(true, 960.f, 540.f, 75.f, 50.f, sf::Color::Blue);
	if (m_fFichier)
	{
		string line;
		int l = 0;
		for (int j = 0; j < 8; j++)
		{
			getline(m_fFichier, line);
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] == 'b') {
					Brick* bBrick = new Brick(true, (600.f + (l * 85.f)) - ((l / 8) * 85.f) * 8, 35.f + ((l / 8) * 85.f), 75.f, 50.f, sf::Color::Blue);
					m_oBricks->push_back(bBrick);
					l += 1;
				}
				else if (line[i] == 'n') {
					Brick* bBrick = new Brick(true, (600.f + (l * 85.f)) - ((l / 8) * 85.f) * 8, 35.f + ((l / 8) * 85.f), NULL, NULL, sf::Color::Blue);
					m_oBricks->push_back(bBrick);
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
