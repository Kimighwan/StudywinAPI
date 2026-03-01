#include "pch.h"
#include "Object.h"
#include "KeyMgr.h"
#include "TimerMgr.h"

Object::Object() : position{}, scale{}
{
	
}

Object::~Object()
{
	
}


void Object::Update()
{
	if (KeyMgr::Instance()->GetKeyState(KEY::LEFT) == KEY_STATE::HOLD)
		position.x -= FDeltaTime * 150.f;
	if (KeyMgr::Instance()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
		position.x += FDeltaTime * 150.f;
	if (KeyMgr::Instance()->GetKeyState(KEY::UP) == KEY_STATE::HOLD)
		position.y -= FDeltaTime * 150.f;
	if (KeyMgr::Instance()->GetKeyState(KEY::DOWN) == KEY_STATE::HOLD)
		position.y += FDeltaTime * 150.f;
}

void Object::Render(HDC backDC)
{
	Rectangle(backDC, position.x - scale.x / 2, position.y - scale.y / 2,
		position.x + scale.x / 2, position.y + scale.y / 2);
}