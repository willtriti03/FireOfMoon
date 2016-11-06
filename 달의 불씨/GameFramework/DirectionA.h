#pragma once
#include "Sprite.h"
#include "Animation.h"
#include "ISceneNode.h"
#include "Timer.h"
#include "SceneManager.h"
#include "MainScene.h"

class DirectionA:public ISceneNode
{
private:
	Sprite *m_pFloor;
	Sprite *m_pPhilla;
	Sprite *m_pGlove;
	Sprite *m_pLight;

	Animation *m_pFire;
	Sprite *m_pCharacter;
	float StartTime;

	bool checkX;
public:
	DirectionA();
	~DirectionA();

	void Update(float eTime);
	void Render();
};

