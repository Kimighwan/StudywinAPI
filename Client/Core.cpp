#include "pch.h"
#include "Core.h"
#include "Object.h"


Object gObj;


Core::Core() : hWnd(0), resolution{}, hDC(0)
{

}

Core::~Core()
{
	ReleaseDC(hWnd, hDC);
}

int Core::Init(HWND _hWnd, POINT _resolution)
{
	hWnd = _hWnd;
	resolution = _resolution;

	// resolution에 맞게 윈도우 크기 조정
	RECT rect = { 0, 0, resolution.x, resolution.y };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(hWnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);

	hDC = GetDC(hWnd);

	//gObj.position = POINT{ resolution.x / 2, resolution.y / 2 };
	//gObj.scale = POINT{ 100, 100 };


	return S_OK;
}

void Core::Progress()
{
	Update();
	Render();
}

void Core::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		//gObj.position.x -= 1;
	}

	if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		//gObj.position.x += 1;
	}
}

void Core::Render()
{
	/*Rectangle(hDC, gObj.position.x - gObj.scale.x / 2, gObj.position.y - gObj.scale.y / 2
		, gObj.position.x + gObj.scale.x / 2, gObj.position.y + gObj.scale.y / 2);*/
}

