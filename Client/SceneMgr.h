#pragma once

class Scene;

class SceneMgr
{
	SINGLE(SceneMgr);

private:
	Scene* scenes[(int)SCENE_TYPE::COUNT];
	Scene* currentScene;

public:
	void Init();
	void Update();
	void Render(HDC backDC);
};

