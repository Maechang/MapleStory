#pragma once
#include "CSingleton.h"
class CSceneManager :
	public CSingleton< CSceneManager>
{
public:
	CSceneManager();
	~CSceneManager();
};

#define SCENE (*CSceneManager::GetInstance())

