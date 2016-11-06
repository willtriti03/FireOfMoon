#ifndef _SPRITEMANAGER_H_
#define _SPRITEMANAGER_H_

#include <d3d9.h>
#include <d3dx9.h>

#define SpriteMgr SpriteManager::GetInstance()

class SpriteManager {
private:
	LPD3DXSPRITE m_pSprite;

private:
	SpriteManager();

public:
	~SpriteManager();
	static SpriteManager* GetInstance() {
		static SpriteManager Instance;
		return &Instance;
	}

	LPD3DXSPRITE Sprite();
	void Initialize();
	void Release();
};

#endif