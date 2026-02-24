#pragma once

class Core
{
	SINGLE(Core);
private:
	HWND hWnd;			// 메인 윈도우 핸들
	POINT resolution;	// 해상도
	HDC hDC;			// Device Context

	HBITMAP backBuffer;	// Double Buffering
	HDC backDC;

public:
	int Init(HWND _hWnd, POINT _resolution);
	void Progress();

private:
	void Update();
	void Render();

public:
	HWND GetMainHwnd() { return hWnd; }
};