#include "pch.h"
#include "Enemy.h"
#include "TimerMgr.h"

Enemy::Enemy() : centerPos(Vec2(0.f, 0.f)), speed(100.f), maxDistance(50.f), dir(1)
{

}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Vec2 curPos = GetPos();
	curPos.x += speed * FDeltaTime * dir;

	float overDistance = abs(centerPos.x - curPos.x) - maxDistance;	// 양수라면 최대 거리를 벗어남
	if (overDistance > 0.f)
	{
		dir *= -1;
		curPos.x += overDistance * dir;
	}

	SetPos(curPos);

}
