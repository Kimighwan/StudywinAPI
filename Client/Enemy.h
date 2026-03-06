#pragma once
#include "Object.h"


class Enemy : public Object
{
private:
	Vec2 centerPos;
	float speed;
	float maxDistance;
	int dir;	// 1(오른쪽), -1(왼쪽)

public:
	Enemy();
	~Enemy();
	void Update() override;

	float GetSpeed() { return speed; }
	void SetSpeed(float _speed) { speed = _speed; }

	void SetCenterPos(Vec2 _centerPos) { centerPos = _centerPos; }
	void SetMoveDistance(float distance) { maxDistance = distance; }
};

