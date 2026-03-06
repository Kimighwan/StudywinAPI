#pragma once
#include "Object.h"


class Bullet : public Object
{
private:
	float angle;
	Vec2 vDir;

public:
	Bullet();
	~Bullet();

	void Update() override;
	void Render(HDC backDC) override;

	void SetDir(float _angle) { angle = _angle; }
	void SetDir(Vec2 _vDir) 
	{ 
		vDir = _vDir; 
		vDir.Normalize();
	}
};

