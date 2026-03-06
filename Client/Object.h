#pragma once

class Object
{
private:
	Vec2 position;
	Vec2 scale;

public:
	Object();
	virtual ~Object();

	void SetPos() { position = Vec2(640.f, 384.f); }
	void SetScale() { scale = Vec2(100.f, 100.f); }
	void SetPos(Vec2 vPos) { position = vPos; }
	void SetScale(Vec2 vScale) { scale = vScale; }

	Vec2 GetPos() { return position; }
	Vec2 GetScale() { return scale; }

	virtual void Update() = 0;
	virtual void Render(HDC backDC);
};

