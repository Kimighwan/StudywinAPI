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

void Object::Render(HDC backDC)
{
	Rectangle(backDC, position.x - scale.x / 2, position.y - scale.y / 2,
		position.x + scale.x / 2, position.y + scale.y / 2);
}