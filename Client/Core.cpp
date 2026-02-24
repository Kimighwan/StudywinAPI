#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimerMgr.h"
#include "KeyMgr.h"

Object gObj;


Core::Core() : hWnd(0), resolution{}, hDC(0), backBuffer(0), backDC(0)
{

}

Core::~Core()
{
	ReleaseDC(hWnd, hDC);
	
	DeleteDC(backDC);
	DeleteObject(backBuffer);
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

	// Double Buffering을 위한 BITMAP과 DC 생성
	backBuffer = CreateCompatibleBitmap(hDC, resolution.x, resolution.y);
	backDC = CreateCompatibleDC(hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(backDC, backBuffer);
	DeleteObject(hOldBit);

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
	// 화면 Clear
	Rectangle(backDC, -1, -1, resolution.x + 1, resolution.y + 1);

	Vec2 pos = gObj.GetPos();
	Vec2 scale = gObj.GetScale();

	Rectangle(backDC, int(pos.x - scale.x / 2.f)
				 , int(pos.y - scale.y / 2.f)
				 , int(pos.x + scale.x / 2.f)
				 , int(pos.y + scale.y / 2.f));

	BitBlt(hDC, 0, 0, resolution.x, resolution.y, backDC, 0, 0, SRCCOPY);
}

