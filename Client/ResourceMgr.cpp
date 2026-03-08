#include "pch.h"
#include "ResourceMgr.h"

#include "PathMgr.h"
#include "Texture.h"

ResourceMgr::ResourceMgr()
{
}

ResourceMgr::~ResourceMgr()
{
	map<wstring, Texture*>::iterator iter = textureResources.begin();
	for (; iter != textureResources.end(); iter++)
		delete iter->second;
}

Texture* ResourceMgr::LoadTexture(const wstring& _key, const wstring& _filePath)
{
	Texture* texture = FindTexture(_key);
	if (nullptr != texture)
		return texture;

	wstring filePath = PathMgr::Instance()->GetContentPath();
	filePath += _filePath;

	texture = new Texture();
	texture->Load(filePath);
	texture->SetKey(_key);
	texture->SetRelativePath(_filePath);

	textureResources.insert(make_pair(_key, texture));
	return texture;
}

Texture* ResourceMgr::FindTexture(const wstring& _key)
{
	map<wstring, Texture*>::iterator iter = textureResources.find(_key);

	if(iter == textureResources.end())
		return nullptr;

	return iter->second;
}