#include "pch.h"
#include "PathMgr.h"

#include "Core.h"

PathMgr::PathMgr() : contentPath{}
{

}

PathMgr::~PathMgr()
{

}

void PathMgr::Init()
{
	GetCurrentDirectory(255, contentPath);

	int pathLen = wcslen(contentPath);
	for(int i = pathLen - 1; i >= 0; --i)
	{
		if (contentPath[i] == L'\\')
		{
			contentPath[i] = L'\0';
			break;
		}
	}

	wcscat_s(contentPath, 255, L"\\Release\\content\\");

	SetWindowText(Core::Instance()->GetMainHwnd(), contentPath);
}