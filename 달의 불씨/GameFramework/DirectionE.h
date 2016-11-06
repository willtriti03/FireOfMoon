#pragma once
#include "ISceneNode.h"
#include "Font.h"
#include "Sprite.h"
#include "Timer.h"
#include "Animation.h"
#include "SceneManager.h"
#include "MainScene.h"
#include "CSound.h"
using namespace std;
class DirectionE:public ISceneNode
{
private:
	int max;
	int *stList;
	int n = 1;
	float limit;
	float timecheck;
	bool check = false;
	Sprite *m_pMap;
	Sprite *m_pPhilla;
	Sprite *m_pCharacter;
	Sprite *m_pLight;
	Sprite *m_pText;
	CSound *m_pQueke;

	Animation *m_pFire;

	D3DXVECTOR2 MapLocation;
	D3DXVECTOR2 PhillaLocation;
	D3DXVECTOR2 CharacterLocation;
	D3DXVECTOR2 LightLocation;
	D3DXVECTOR2 FireLocation;

public:
	DirectionE();
	~DirectionE();

	void Update(float eTime);
	void Render();
};

