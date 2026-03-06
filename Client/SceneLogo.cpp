#include "pch.h"
#include "SceneLogo.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Core.h"

SceneLogo::SceneLogo()
{
}

SceneLogo::~SceneLogo()
{
}

void SceneLogo::Enter()
{
	Object* newOB = new Player();
	newOB->SetPos();
	newOB->SetScale();
	AddObject(newOB, OBJECT_TYPE::DEFAULT);

	// 테스트 몬스터 배치
	int enemyCount = 10;
	float moveDist = 25.f;
	float objectScale = 50.f;


	Vec2 vResolution = Core::Instance()->GetResolution();
	float interval = (vResolution.x - ((moveDist + objectScale / 2.f) * 2)) / (float)(enemyCount - 1);	// 4칸으로 나눈 간격 만큼 몬스터를 배치

	Enemy* enemy = nullptr;

	for (int i = 0; i < enemyCount; i++)
	{
		enemy = new Enemy();
		enemy->SetPos(Vec2((moveDist + objectScale / 2.f) + (float)i * interval, 50.f));
		enemy->SetCenterPos(enemy->GetPos());
		enemy->SetMoveDistance(moveDist);
		enemy->SetScale(Vec2(objectScale, objectScale));
		AddObject(enemy, OBJECT_TYPE::DEFAULT);
	}
}

void SceneLogo::Exit()
{
}
