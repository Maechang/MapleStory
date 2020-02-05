#pragma once
#include "CSingleton.h"
class CInputManager :
	public CSingleton< CInputManager>
{
public:
	CInputManager();
	~CInputManager();
};

