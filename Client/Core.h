#pragma once

class Core
{
private:
	HWND hWnd;			// 메인 윈도우 핸들
	POINT resolution;	// 해상도
	HDC hDC;			// Device Context

public:
	SINGLE(Core);
	int Init(HWND _hWnd, POINT _resolution);
	void Progress();

private:
	void Update();
	void Render();

private:
	Core();
	~Core();
};