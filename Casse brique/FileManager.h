#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Brick.h"
using namespace std;

class FileManager
{
	public:
		string m_sLine;
		fstream m_fFichier;

		FileManager();

		void CreateLevel(const char* cnameFile, vector<Brick*>* m_oBricks);
};