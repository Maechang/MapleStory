#include "stdafx.h"

//메이플 스토리 모작 프로젝트
//게임명 : 메이플스토리
//제작 기간 : 2020/01/16 ~
//제작 엔진 : DirectX9

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	// 시스템 클래스를 생성
	CSystem * MainSystem = new CSystem();

	// 초기화 및 메세지루프와 릴리즈
	MainSystem->Init();

	MainSystem->Main_Loop();

	MainSystem->Release();
}