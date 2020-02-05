#pragma once

using Vector2 = D3DXVECTOR2;
using Vector3 = D3DXVECTOR3;
using Matrix = D3DXMATRIX;

#define SAFE_DELETE(var) if(var) delete var; var = nullptr;
#define SAFE_RELEASE(var) if(var) var->Release(); var = nullptr;



#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


