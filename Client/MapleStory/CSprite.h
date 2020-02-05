#pragma once
class CSprite
{
	friend class CGraphicsManager;
public:
	CSprite();
	~CSprite();

private:
	LPDIRECT3DTEXTURE9 m_pTexture = nullptr;
	D3DXIMAGE_INFO m_Info;

public:
	LPDIRECT3DTEXTURE9 GetD3DXTexture() { return m_pTexture; }
	Vector2 GetImageSize() { return Vector2(m_Info.Width, m_Info.Height); }
};
