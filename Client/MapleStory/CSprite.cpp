#include "stdafx.h"
#include "CSprite.h"


CSprite::CSprite()
{
}


CSprite::~CSprite()
{
	SAFE_RELEASE(this->m_pTexture);
}
