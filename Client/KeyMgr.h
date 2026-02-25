#pragma once

enum class KEY_STATE
{
	NONE, DOWN, UP, HOLD,
	COUNT
};

enum class KEY
{
	LEFT, RIGHT, UP, DOWN, 
	SPACE, SHIFT, CTRL, ALT, ENTER, ESC,
	Q, W, E, R, I, O, A, S, D, F, Z, X, C, V,
	COUNT
};

struct sKeyInfo
{
	KEY_STATE state;
	bool bPrev;			// 이전 프레임에서 눌렀는지 여부
};

class KeyMgr
{
	SINGLE(KeyMgr);

private:
	vector<sKeyInfo> vecKey;

public:
	void Init();
	void Update();

public:
	KEY_STATE GetKeyState(KEY key) { return vecKey[(int)key].state; }
};

