#include "pch.h"
#include "SceneMgr.h"

#include "SceneLogo.h"


SceneMgr::SceneMgr() : scenes{}, currentScene(nullptr)
{ 
}

SceneMgr::~SceneMgr()
{
	for(int i = 0; i < (int)SCENE_TYPE::COUNT; ++i)
	{
		if (scenes[i] != nullptr)
		{
			delete scenes[i];
			scenes[i] = nullptr;
		}
	}
}

void SceneMgr::Init()
{
	// 일단 Logo Scene 만 생성
	//scenes[(int)SCENE_TYPE::TOOL] = new SceneTool();
	scenes[(int)SCENE_TYPE::LOGO] = new SceneLogo();
	scenes[(int)SCENE_TYPE::LOGO]->SetName(L"Logo Scene");
	//scenes[(int)SCENE_TYPE::LOBBY] = new SceneLobby();
	//scenes[(int)SCENE_TYPE::TITLE] = new SceneTitle();
	//scenes[(int)SCENE_TYPE::INGAME] = new SceneIngame();


	currentScene = scenes[(int)SCENE_TYPE::LOGO];
	currentScene->Enter();
}


void SceneMgr::Update()
{
	currentScene->Update();
}

void SceneMgr::Render(HDC backDC)
{
	currentScene->Render(backDC);
}
