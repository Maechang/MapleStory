#pragma once
#include "resource.h"
#include "targetver.h"
//#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
using namespace std;

//C++ 헤더 파일
#include <windows.h>
#include <time.h>
#include <timeapi.h>
#include <mmsystem.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <thread>
#include <future>
#include <string>

//DirectX 헤더파일
#include <d3d9.h>
#include "../Lib/Include/d3dx9.h"
#include <d3d.h>

//추가 헤더파일
#include "Define.h"
#include "CSystem.h"
#include "CGameObject.h"
#include "CComponent.h"
#include "CSprite.h"
#include "CFrameSkip.h"

//매니저
#include "CSingleton.h"
#include "CGraphicsManager.h"
#include "CPropertyManager.h"
#include "CInputManager.h"
#include "CObjectManger.h"
#include "CPhysicsManager.h"

//lib 파일
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "../Lib/x86/d3d9.lib")
#pragma comment(lib, "../Lib/x86/d3dx9.lib")



