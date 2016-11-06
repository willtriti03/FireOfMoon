#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "Timer.h"

class ShakeScene :public ISceneNode
{
private:
	Sprite *m_pBackground;
	float limit;
	int cnt = -10;
	int n = 1;
public:
	ShakeScene();
	~ShakeScene();

	void Update(float eTime);
	void Render();
};