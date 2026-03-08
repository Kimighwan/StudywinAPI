#include "pch.h"
#include "TimerMgr.h"
#include "Core.h"

TimerMgr::TimerMgr() 
	: curCount{}, prevCount{}, frequency{}	// union이라 초기화를 이런식으로 함.
	, deltaTime(0.)
	, accumulatedTime(0.)
	, callCount(0)
	, fps(0)
{
	
}

TimerMgr::~TimerMgr()
{

}

void TimerMgr::Init()
{
	QueryPerformanceCounter(&prevCount);
	QueryPerformanceFrequency(&frequency);
}

void TimerMgr::Update()
{
	QueryPerformanceCounter(&curCount);

	// 이전 프레임의 카운팅과 현재 프레임의 카운팅 값의 차이를 구한다.
	// 초당 카운팅 값을 나누어 한 프레임에 걸린 시간을 구한다.
	deltaTime = ((double)curCount.QuadPart - (double)prevCount.QuadPart) / (double)frequency.QuadPart;

	prevCount = curCount;
}

void TimerMgr::Render()
{
	++callCount;
	accumulatedTime += deltaTime;

	if (accumulatedTime >= 1.)
	{
		fps = callCount;
		accumulatedTime = 0.;
		callCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, deltaTime : %f", fps, deltaTime);
		SetWindowText(Core::Instance()->GetMainHwnd(), szBuffer);
	}
}
