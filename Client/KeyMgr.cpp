#include "pch.h"
#include "KeyMgr.h"
#include "Core.h"

int arrVitualKey[(int)KEY::COUNT] = {
	VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	VK_SPACE, VK_SHIFT, VK_CONTROL, VK_MENU, VK_RETURN, VK_ESCAPE,
	'Q', 'W', 'E', 'R', 'I', 'O', 'A', 'S', 'D', 'F', 'Z', 'X', 'C', 'V'
};

KeyMgr::KeyMgr()
{
}

KeyMgr::~KeyMgr()
{
}

void KeyMgr::Init()
{
	for (int i = 0; i < (int)KEY::COUNT; ++i)
	{
		vecKey.push_back({ KEY_STATE::NONE, false });
	}
}

void KeyMgr::Update()
{
	// 윈도우 포커싱 감지
	// HWND hMainWnd = Core::Instance()->GetMainHwnd();
	HWND hWnd = GetFocus();

	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::COUNT; ++i)
		{
			if (GetAsyncKeyState(arrVitualKey[i]) & 0x8000)
			{
				if (vecKey[i].bPrev)
					vecKey[i].state = KEY_STATE::HOLD;
				else
					vecKey[i].state = KEY_STATE::DOWN;

				vecKey[i].bPrev = true;
			}
			else
			{
				if (vecKey[i].bPrev)
					vecKey[i].state = KEY_STATE::UP;
				else
					vecKey[i].state = KEY_STATE::NONE;

				vecKey[i].bPrev = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::COUNT; ++i)
		{
			vecKey[i].bPrev = false;

			if (vecKey[i].state == KEY_STATE::DOWN || vecKey[i].state == KEY_STATE::HOLD)
				vecKey[i].state = KEY_STATE::UP;
			else if (vecKey[i].state == KEY_STATE::UP)
				vecKey[i].state = KEY_STATE::NONE;
		}
	}

}
