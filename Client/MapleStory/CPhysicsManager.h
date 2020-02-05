#pragma once
#include "CSingleton.h"
class CPhysicsManager :
	public CSingleton< CPhysicsManager>
{
public:
	CPhysicsManager();
	~CPhysicsManager();
};

