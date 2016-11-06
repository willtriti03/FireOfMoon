#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "Animation.h"
#include "Timer.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "CurtainCall.h"

class DirectionH:public ISceneNode
{
private:
	Animation *m_pFire;
	
	Sprite *m_pPhilla;
	Sprite *m_pCharacter;
	Sprite *m_pMap;
	Sprite *m_pLight;
	Animation *m_pMoon;
	CurtainCall *m_pCurtainCall;

	bool check = false;
	float StartTime;
	float StartTimePlus;
public:
	DirectionH();
	~DirectionH();

	void Update(float eTime);
	void Render();
};

