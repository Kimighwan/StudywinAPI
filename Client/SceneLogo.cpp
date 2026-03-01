#include "pch.h"
#include "SceneLogo.h"
#include "Object.h"

SceneLogo::SceneLogo()
{
}

SceneLogo::~SceneLogo()
{
}

void SceneLogo::Enter()
{
	Object* newOB = new Object();

	newOB->SetPos();
	newOB->SetScale();

	AddObject(newOB, OBJECT_TYPE::DEFAULT);
}

void SceneLogo::Exit()
{
}
