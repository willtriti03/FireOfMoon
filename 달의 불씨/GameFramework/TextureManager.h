#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include <map>

#define TextureMgr TextureManager::GetInstance()

class TextureManager {
private:
	typedef std::map<std::string, LPDIRECT3DTEXTURE9> TEXTURE;
	TEXTURE m_textureMap;

private:
	TextureManager();

public:
	~TextureManager();
	static TextureManager* GetInstance() {
		static TextureManager Instance;
		return &Instance;
	}

	LPDIRECT3DTEXTURE9 LoadTextureFromFile(std::string path);
	void Release();
};


#endif