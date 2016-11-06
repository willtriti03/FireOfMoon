#pragma once
#include "ISceneNode.h"
#include "Animation.h"
#include "Sprite.h"
#include "Timer.h"
#include "CSound.h"
class DirectionB:public ISceneNode
{
private:
	float StartTime;
	bool check = true;

	Sprite *m_pFloor;
	Sprite *m_pPhilla;
	Sprite *m_pGlove;
	Sprite *m_pLight;

	Animation *m_pFire;
	Animation *m_pCharacterRight;

	CSound *m_pWalk;

	D3DXVECTOR2 Light;
	D3DXVECTOR2 Fire;
	D3DXVECTOR2 Floor;
	D3DXVECTOR2 Philla;
	D3DXVECTOR2 Character;
public:
	DirectionB();
	~DirectionB();

	void Update(float eTime);
	void Render();
};

