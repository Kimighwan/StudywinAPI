#include "pch.h"
#include "Core.h"

#include "TimerMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "PathMgr.h"


Core::Core() : hWnd(0), resolution{}, hMainDC(0), backBuffer(0), backDC(0)
{

}

Core::~Core()
{
	ReleaseDC(hWnd, hMainDC);
	
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

	hMainDC = GetDC(hWnd);

	// Double Buffering을 위한 BITMAP과 DC 생성
	backBuffer = CreateCompatibleBitmap(hMainDC, resolution.x, resolution.y);
	backDC = CreateCompatibleDC(hMainDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(backDC, backBuffer);
	DeleteObject(hOldBit);

	// Manager 초기화
	PathMgr::Instance()->Init();
	TimerMgr::Instance()->Init();
	KeyMgr::Instance()->Init();
	SceneMgr::Instance()->Init();


	return S_OK;
}


void Core::Progress()
{
	// Manager 업데이트
	TimerMgr::Instance()->Update();
	KeyMgr::Instance()->Update();


	SceneMgr::Instance()->Update();

#pragma region Rendering

	// 화면 Clear
	Rectangle(backDC, -1, -1, resolution.x + 1, resolution.y + 1);

	SceneMgr::Instance()->Render(backDC);

	BitBlt(hMainDC, 0, 0, resolution.x, resolution.y, backDC, 0, 0, SRCCOPY);

	//TimerMgr::Instance()->Render();

#pragma endregion
}
