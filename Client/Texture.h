#pragma once
#include "CResource.h"


class Texture : public CResource
{
public:
	void Load(const wstring& filePath);

	UINT Width() { return bitmapInfo.bmWidth; }
	UINT Height() { return bitmapInfo.bmHeight; }

	HDC GetDC() { return dc; }

private:
	Texture();
	~Texture() override;
	friend class ResourceMgr;

	HDC dc;
	HBITMAP bitmap;
	BITMAP bitmapInfo;
};

