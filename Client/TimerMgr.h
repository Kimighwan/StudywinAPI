#pragma once


class TimerMgr
{
	SINGLE(TimerMgr);
private:
	LARGE_INTEGER curCount;		// 현재 카운트
	LARGE_INTEGER prevCount;	// 이전 카운트
	LARGE_INTEGER frequency;	// 초당 카운트 횟수

	double deltaTime;			// 한 프레임에 걸린 시간 - 프레임 사이의 시간 값
	double accumulatedTime;		// 1초 체크를 위한 누적 시간
	UINT callCount;				// 호출 횟수 체크
	UINT fps;

public:
	void Init();
	void Update();
	void Render();

public:
	double GetDeltaTime() { return deltaTime; }
	float GetFDeltaTime() { return (float)deltaTime; }
};

