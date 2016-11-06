#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "Animation.h"
#include "Timer.h"
#include "SceneManager.h"
#include "MainScene.h"
#include "CSound.h"
class DirectionC:public ISceneNode
{
private:
	Sprite *m_pFloor;
	Sprite *m_pPhilla;
	Sprite *m_pLight;

	CSound *m_pQueke;

	Animation *m_pFire;
	Sprite *m_pCharacter;

	D3DXVECTOR2 Light;
	D3DXVECTOR2 Fire;
	D3DXVECTOR2 Floor;
	D3DXVECTOR2 Philla;
	D3DXVECTOR2 Character;
	float limit;
	int n = 1;
public:
	DirectionC();
	~DirectionC();

	void Update(float eTime);
	void Render();
};

