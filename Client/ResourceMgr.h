#pragma once

class Texture;

class ResourceMgr
{
	SINGLE(ResourceMgr);

public:
	Texture* LoadTexture(const wstring& _key, const wstring& _filePath);
	Texture* FindTexture(const wstring& _key);

private:
	map<wstring, Texture*> textureResources;

};

