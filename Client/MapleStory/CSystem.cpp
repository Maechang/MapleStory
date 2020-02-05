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
	static DWORD frameCount = 0;            //프레임 카운트수
	static float timeElapsed = 0.0f;            //흐른 시간
	static DWORD lastTime = timeGetTime();   //마지막 시간(temp변수)

	DWORD curTime = timeGetTime();      //현재 시간
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.

	timeElapsed += timeDelta;

	frameCount++;

	if (timeElapsed >= 1.0f)         //흐른시간이 1초이상이면 내가 하고싶은것 처리
	{
		m_fFPS = (float)frameCount / timeElapsed;
		m_fDeltaTime = 1.0f / m_fFPS;

		printf("FPS : %.f  Delta : %f\n", m_fFPS, m_fDeltaTime);
		frameCount = 0;
		timeElapsed = 0.0f;
	}
	else
	{
		//흐른 시간이 1초가 안되면 생략함  
		//Sleep() 해도되고 안해도 되구~ 
	}


	lastTime = curTime;
}


