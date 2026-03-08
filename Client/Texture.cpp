#include "pch.h"
#include "Texture.h"
#include "Core.h"

Texture::Texture() : dc(0), bitmap(0), bitmapInfo{}
{
}

Texture::~Texture()
{
	DeleteDC(dc);
	DeleteObject(bitmap);
}

void Texture::Load(const wstring& filePath)
{
	// 파일로 부터 로딩한 데이터를 비트맵으로 생성
	bitmap = (HBITMAP)LoadImage(nullptr, filePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(bitmap);

	// DC 생성후 비트맵과 연결
	dc = CreateCompatibleDC(Core::Instance()->GetMainDC());
	HBITMAP preBitmap = (HBITMAP)SelectObject(dc, bitmap);
	DeleteObject(preBitmap);

	// BITMAP 정보
	GetObject(bitmap, sizeof(BITMAP), &bitmapInfo);
}