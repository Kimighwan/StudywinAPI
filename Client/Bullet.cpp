#include "pch.h"
#include "Bullet.h"
#include "TimerMgr.h"

Bullet::Bullet() : angle(pi / 4.f), vDir(Vec2(1.f, 1.f))
{
	vDir.Normalize();
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Vec2 curPos = GetPos();

	// 벡터의 정규화 개념을 사용하지 않고 직접 각도를 이용하여 이동하는 방법
	/*curPos.x += cosf(angle) * 600.f * FDeltaTime; 
	curPos.y -= sinf(angle) * 600.f * FDeltaTime;*/

	curPos.x += vDir.x * 600.f * FDeltaTime;
	curPos.y += vDir.y * 600.f * FDeltaTime;

	SetPos(curPos);
}

void Bullet::Render(HDC backDC)
{
	Vec2 position = GetPos();
	Vec2 scale = GetScale();

	Ellipse(backDC, position.x - scale.x / 2, position.y - scale.y / 2,
		position.x + scale.x / 2, position.y + scale.y / 2);
}
