#include "stdafx.h"
#include "CPropertyManager.h"


CPropertyManager::CPropertyManager()
{
	this->m_iWidth = 1920;
	this->m_iHeight = 1080;
	this->m_bWindowed = true;
	ReadProperty();
}


CPropertyManager::~CPropertyManager()
{
}

void CPropertyManager::InitSetting()
{
}

void CPropertyManager::ReadProperty()
{
	ifstream readFile;

	readFile.open("Setting.Maple", ios::binary | ios::in);
	if (readFile.is_open() == false)
	{
		WriteProperty();
	}
	else
	{
		int size = readFile.tellg();
		char* str = new char[size];
		readFile.read(str, size);
	}
	readFile.close();
}

void CPropertyManager::WriteProperty()
{
	ofstream writeFile;
	writeFile.open("Setting.Maple",ios::binary | ios::out);
	writeFile.clear();

	writeFile.write((char*)(this), sizeof(CPropertyManager));
	writeFile.close();
}

