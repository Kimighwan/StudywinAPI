#pragma once

class Object
{
private:
	Vec2 position;
	Vec2 scale;

public:
	void SetPos(Vec2 vPos) { position = vPos; }
	void SetScale(Vec2 vScale) { scale = vScale; }

	Vec2 GetPos() { return position; }
	Vec2 GetScale() { return scale; }
public:
	Object();
	~Object();
};

