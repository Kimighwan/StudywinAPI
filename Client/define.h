#pragma once

#define SINGLE(type) public:\
						static type* Instance() { static type instance; return &instance; }\
					private: type(); ~type();

#define FDeltaTime TimerMgr::Instance()->GetFDeltaTime()
#define DeltaTime TimerMgr::Instance()->GetDeltaTime()

enum class OBJECT_TYPE
{
	DEFAULT,
	PLAYER,
	ENEMY,
	EFFECT,
	UI,

	COUNT = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	LOGO,
	TITLE,
	LOBBY,
	INGAME,
	COUNT,
};