#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimerMgr.h"
#include "Bullet.h"
#include "Scene.h"
#include "SceneMgr.h"

void Player::Update()
{
	Vec2 vPos = GetPos();

	if (KeyMgr::Instance()->GetKeyState(KEY::LEFT) == KEY_STATE::HOLD)
		vPos.x -= FDeltaTime * 150.f;
	if (KeyMgr::Instance()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
		vPos.x += FDeltaTime * 150.f;
	if (KeyMgr::Instance()->GetKeyState(KEY::UP) == KEY_STATE::HOLD)
		vPos.y -= FDeltaTime * 150.f;
	if (KeyMgr::Instance()->GetKeyState(KEY::DOWN) == KEY_STATE::HOLD)
		vPos.y += FDeltaTime * 150.f;

	SetPos(vPos);

	if (KEY_DOWN(KEY::SPACE))
	{
		CreateBullet();
	}
}

void Player::CreateBullet()
{
	Vec2 bulletPos = GetPos();
	bulletPos.y -= GetScale().y / 2.f;

	Bullet* newBullet = new Bullet();
	newBullet->SetPos(bulletPos);
	newBullet->SetScale(Vec2(20.f, 20.f));
	newBullet->SetDir(Vec2(-1.f, -7.f));

	Scene* curScene = SceneMgr::Instance()->GetCurScene();
	curScene->AddObject(newBullet, OBJECT_TYPE::DEFAULT);
}

