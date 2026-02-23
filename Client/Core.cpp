#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimerMgr.h"
#include "KeyMgr.h"

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

	// Manager 초기화
	TimerMgr::Instance()->Init();
	KeyMgr::Instance()->Init();


	gObj.SetPos(Vec2((float)(resolution.x / 2), (float)(resolution.y / 2)));
	gObj.SetScale(Vec2(100, 100));


	return S_OK;
}

void Core::Progress()
{
	// Manager 업데이트
	TimerMgr::Instance()->Update();

	Update();
	Render();
}

void Core::Update()
{
	Vec2 pos = gObj.GetPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		pos.x -= 200.f * fDeltaTime;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		pos.x += 200.f * TimerMgr::Instance()->GetFDeltaTime();
	}

	gObj.SetPos(pos);
}

void Core::Render()
{
	Vec2 pos = gObj.GetPos();
	Vec2 scale = gObj.GetScale();

	Rectangle(hDC, int(pos.x - scale.x / 2.f)
				 , int(pos.y - scale.y / 2.f)
				 , int(pos.x + scale.x / 2.f)
				 , int(pos.y + scale.y / 2.f));
}

