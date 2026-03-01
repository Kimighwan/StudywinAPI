#pragma once
#include "Scene.h"

class SceneLogo : public Scene
{

public:
	SceneLogo();
	~SceneLogo();


	void Enter() override;
	void Exit() override;

};

