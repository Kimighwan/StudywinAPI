#include "pch.h"
#include "Scene.h"

#include "Object.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for(int i = 0 ; i < (int)OBJECT_TYPE::COUNT; i++)
	{
		for (size_t j = 0; j < objects[i].size(); j++)
		{
			delete objects[i][j];
		}
	}
}

void Scene::Update()
{
	for (int i = 0; i < (int)OBJECT_TYPE::COUNT; i++)
	{
		for (int j = 0; j < objects[i].size(); j++)
		{
			objects[i][j]->Update();
		}
	}
}

void Scene::Render(HDC backDC)
{
	for (int i = 0; i < (int)OBJECT_TYPE::COUNT; i++)
	{
		for (int j = 0; j < objects[i].size(); j++)
		{
			objects[i][j]->Render(backDC);
		}
	}
}