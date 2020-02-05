#include "stdafx.h"
#include "CComponent.h"


CComponent::CComponent()
{
	this->m_bEnable = true;
	this->m_bStart = false;
	this->m_pGameObject = nullptr;
}


CComponent::~CComponent()
{
}
