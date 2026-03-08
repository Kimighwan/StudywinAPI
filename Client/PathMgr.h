#pragma once

class PathMgr
{
	SINGLE(PathMgr);

public:
	void Init();	// 절대 경로 찾기
	const wchar_t* GetContentPath() { return contentPath; }

private:
	wchar_t contentPath[255];
};

