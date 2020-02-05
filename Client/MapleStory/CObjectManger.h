#pragma once
#include "CSingleton.h"
class CObjectManger :
	public CSingleton< CObjectManger>
{
public:
	CObjectManger();
	~CObjectManger();
};

