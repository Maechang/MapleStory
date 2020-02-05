#include "stdafx.h"
#include "CSystem.h"

CSystem::CSystem()
{
}


CSystem::~CSystem()
{
}

void CSystem::Init()
{
	GRAPHICS.Init();
	GRAPHICS.LoadSprite("../resource/51251.png");
}


void CSystem::Release()
{
	GRAPHICS.ReleaseInstance();
}

void CSystem::Main_Loop()
{
	MSG msg;
	CFrameSkip A;
	A.SetFramePerSec(10.f);
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (m_fDeltaTime > 0)
			{
				if (A.Update(m_fDeltaTime))
				{
					GRAPHICS.RenderStart();

					GRAPHICS.RenderSprite(GRAPHICS.GetSprite("51251"));
					
					GRAPHICS.RenderEnd();
				}
			}
			UpdateFPS();
		}
	}
}


void CSystem::UpdateFPS()
{
	static DWORD frameCount = 0;            //������ ī��Ʈ��
	static float timeElapsed = 0.0f;            //�帥 �ð�
	static DWORD lastTime = timeGetTime();   //������ �ð�(temp����)

	DWORD curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.

	timeElapsed += timeDelta;

	frameCount++;

	if (timeElapsed >= 1.0f)         //�帥�ð��� 1���̻��̸� ���� �ϰ������ ó��
	{
		m_fFPS = (float)frameCount / timeElapsed;
		m_fDeltaTime = 1.0f / m_fFPS;

		printf("FPS : %.f  Delta : %f\n", m_fFPS, m_fDeltaTime);
		frameCount = 0;
		timeElapsed = 0.0f;
	}
	else
	{
		//�帥 �ð��� 1�ʰ� �ȵǸ� ������  
		//Sleep() �ص��ǰ� ���ص� �Ǳ�~ 
	}


	lastTime = curTime;
}


