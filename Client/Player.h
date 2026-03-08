#pragma once
#include "Object.h"

class Texture;

class Player : public Object
{
public:
	Player();
	~Player() override;
	void Update() override;
	void Render(HDC backDC) override;
	void CreateBullet();

private:
	Texture* texture;
};

