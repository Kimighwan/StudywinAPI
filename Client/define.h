#pragma once

#define SINGLE(type) public:\
						static type* Instance() { static type instance; return &instance; }\
					private: type(); ~type();

#define FDeltaTime TimerMgr::Instance()->GetFDeltaTime()
#define DeltaTime TimerMgr::Instance()->GetDeltaTime()

#define KEY_CHECK(key, state) KeyMgr::Instance()->GetKeyState(key) == state
#define KEY_DOWN(key) KEY_CHECK(key, KEY_STATE::DOWN)
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_UP(key) KEY_CHECK(key, KEY_STATE::UP)

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