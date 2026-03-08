#pragma once

class CResource
{
private:
	wstring key;
	wstring relativePath;	// 상대 경로

public:
	void SetKey(const wstring& _key) { key = _key; }
	void SetRelativePath(const wstring& _relativePath) { relativePath = _relativePath; }

	const wstring& GetKey() const { return key; }
	const wstring& GetRelativePath() const { return relativePath; }

public:
	CResource();
	virtual ~CResource();
};