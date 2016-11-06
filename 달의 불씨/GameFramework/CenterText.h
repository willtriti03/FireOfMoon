#pragma once
#include "Sprite.h"
#include "ISceneNode.h"

class CenterText :public ISceneNode
{
private:
	Sprite *m_pBackground;
public:
	CenterText();
	~CenterText();

	void Update(float eTime);
	void Render();
	void SetBGMiddle(Sprite *m_pBackground);
};