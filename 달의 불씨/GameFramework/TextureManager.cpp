#include "Application.h"
#include "TextureManager.h"

TextureManager::TextureManager() {}
TextureManager::~TextureManager() {}
LPDIRECT3DTEXTURE9 TextureManager::LoadTextureFromFile(std::string path) {
	if(m_textureMap[path] != NULL)
		return m_textureMap[path];

	D3DXCreateTextureFromFileExA(
		GameApp->GetDevice(),
		path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		NULL,
		NULL,
		NULL,
		&m_textureMap[path]);
	return m_textureMap[path];
}
void TextureManager::Release() {
	TEXTURE::iterator it;
	for(it = m_textureMap.begin();it != m_textureMap.end(); ++it)
		it->second->Release();
}