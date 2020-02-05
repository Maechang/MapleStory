#pragma once
class CSystem
{
public:
	CSystem();
	~CSystem();

	void Init();
	void Release();
	void Main_Loop();
	void UpdateFPS();

	float m_fDeltaTime = -1.f;
	float m_fFPS = -1.f;
};

