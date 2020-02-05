#pragma once
class CGraphicsManager 
	: public CSingleton< CGraphicsManager >
{
public:
	CGraphicsManager();
	~CGraphicsManager();

public:
	void Init();
	void RenderStart();
	void RenderEnd();
	void Release();

	HRESULT LoadSprite(string _Path);
    HRESULT LoadSprite(string _Path, int _iAmount);

	CSprite *		GetSprite(string _Name);
	list<CSprite *>& GetSprite(string _Name, int _iAmount);

	void RenderSprite(CSprite * _pSprite);
private:
	map<string, LPD3DXFONT> m_mapFont;
	map<string, CSprite * > m_mapTexture;

	LPD3DXSPRITE m_pSprite = nullptr;
	LPD3DXFONT   m_pFont = nullptr;


	LPDIRECT3D9	m_pD3D = nullptr;
	LPDIRECT3DDEVICE9 m_pD3DDevice = nullptr;
	HWND m_hWND;


	LPDIRECT3D9 GetD3D() { return m_pD3D; }
	LPDIRECT3DDEVICE9 GetD3DDevice() { return m_pD3DDevice; }
	HWND GetHWND() { return m_hWND; }
};

#define GRAPHICS (*CGraphicsManager::GetInstance())

