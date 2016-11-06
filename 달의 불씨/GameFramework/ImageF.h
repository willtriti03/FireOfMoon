#pragma once
#include "ISceneNode.h"
#include "Timer.h"
#include "Sprite.h"
#include "CurtainCall.h"
#include "SceneManager.h"
class ImageF:public ISceneNode
{
private:
	bool rd = false;
	float time;
	float time2;
	Sprite *m_pText;
	CurtainCall *m_pCurtain;
public:
	ImageF();
	~ImageF();

	void Update(float eTime);
	void Render();
};

