#pragma once
#include "ISceneNode.h"
#include "Timer.h"
#include "Sprite.h"
#include "CurtainCall.h"
#include "SceneManager.h"
class ImageT :public ISceneNode
{
private:
	bool rd = false;
	float time;
	float time2;
	Sprite *m_pText;
	CurtainCall *m_pCurtain;
public:
	ImageT();
	~ImageT();

	void Update(float eTime);
	void Render();
};

