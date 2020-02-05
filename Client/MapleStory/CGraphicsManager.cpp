#include "stdafx.h"
#include "CGraphicsManager.h"


CGraphicsManager::CGraphicsManager()
{
}


CGraphicsManager::~CGraphicsManager()
{
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// 메인 프록시저

	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void CGraphicsManager::Init()
{
	// 윈도우 클래스를 생성후 적용
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		L"MapleStory", NULL
	};
	RegisterClassEx(&wc);

	// 윈도우를 생성후
	m_hWND = CreateWindow(L"MapleStory", L"MapleStory",
		WS_OVERLAPPEDWINDOW, 0, 0, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	// 보여주고 업데이트를 한다.
	ShowWindow(m_hWND, SW_SHOWDEFAULT);
	UpdateWindow(m_hWND);

	// D3D 초기화
	this->m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	// true면 창모드, false면 전체화면
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	// 디바이스 생성
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWND,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &this->m_pD3DDevice);

	D3DXCreateSprite(this->m_pD3DDevice, &this->m_pSprite);
}

void CGraphicsManager::RenderStart()
{
	this->m_pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	this->m_pD3DDevice->BeginScene();
	this->m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CGraphicsManager::RenderEnd()
{
	
	this->m_pSprite->End();
	m_pD3DDevice->EndScene();
	m_pD3DDevice->Present(nullptr, nullptr, nullptr, nullptr);
}

void CGraphicsManager::Release()
{
	for (auto iter : m_mapTexture)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapTexture.clear();
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pD3DDevice);
	SAFE_RELEASE(m_pD3D);

}

HRESULT CGraphicsManager::LoadSprite(string _Path)
{
	if (_Path.length() <= 4)
	{
		//BUG
		return E_FAIL;
	}

	string name;
	for (int i = _Path.length()-1; i >= 0; i--)
	{
		if (_Path[i] == '/')
		{
			name = _Path.substr(i+1, _Path.length() - i - 1 - 4);
			break;
		}
	}

	for (auto iter : m_mapTexture)
	{
		if (iter.first == name)
		{
			return E_FAIL;
		}
	}

	LPDIRECT3DTEXTURE9 d3dTexture = nullptr;
	D3DXIMAGE_INFO d3dInfo;

	if (S_OK == D3DXCreateTextureFromFileExA(
		this->m_pD3DDevice,
		_Path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		0,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		&d3dInfo,
		nullptr,
		&d3dTexture
	))

	{
		CSprite * pSprite = new CSprite();
		pSprite->m_pTexture = d3dTexture;
		pSprite->m_Info = d3dInfo;

		this->m_mapTexture.insert(make_pair(name, pSprite));
	}
	else
	{
		//BUG
		return E_FAIL;
	}
}


HRESULT CGraphicsManager::LoadSprite(string _Path, int _iAmount)
{
	if (_Path.length() <= 4)
	{
		//BUG
		return E_FAIL;
	}
	if (_iAmount < 1)
	{
		//BUG
		return E_FAIL;
	}
	_Path.erase(_Path.length() - 4, 4);
	list <CSprite *> listSprite;
	for (int i = 1; i <= _iAmount; i++)
	{
		if (E_FAIL == this->LoadSprite(_Path + " ("s + to_string(i) + ").png"s))
		{
			//BUG
		}
	}
	return S_OK;

}

CSprite * CGraphicsManager::GetSprite(string _Name)
{
	for (auto iter : m_mapTexture)
	{
		if (iter.first == _Name)
		{
			return iter.second;
		}
	}
	return nullptr;
}

list<CSprite*>& CGraphicsManager::GetSprite(string _Name, int _iAmount)
{
	list<CSprite*> listSprite;

	for(int i = 1; i<= _iAmount; i++)
	{
		CSprite * pSprite = GetSprite(_Name + " ("s + to_string(i) + ")"s);
		listSprite.push_back(pSprite);
	}

	return listSprite;
}

void CGraphicsManager::RenderSprite(CSprite * _pSprite)
{
	Matrix WorldMatrix;

	D3DXMatrixTranslation(&WorldMatrix, 500, 200, 0.f);

	this->m_pSprite->SetTransform(&WorldMatrix);

	this->m_pSprite->Draw(_pSprite->m_pTexture, nullptr, nullptr, nullptr, D3DCOLOR_ARGB(255, 255, 255, 255));
}
