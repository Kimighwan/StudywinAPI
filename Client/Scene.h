#pragma once

class Object;

class Scene
{
private:
	vector<Object*> objects[(int)OBJECT_TYPE::COUNT];
	wstring sceneName;

protected:
	void AddObject(Object* obj, OBJECT_TYPE type)
	{
		objects[(int)type].push_back(obj);
	}

public:
	Scene();
	virtual ~Scene();

	virtual void Enter() = 0;		// Scene 시작 시
	virtual void Exit() = 0;		// Scene 종료 시

	void SetName(const wstring& _name) { sceneName = _name; }
	const wstring& GetName() { return sceneName; }

	void Update();
	void Render(HDC backDC);
};