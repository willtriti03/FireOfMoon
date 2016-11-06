#pragma once
#include "Animation.h"
#include "ISceneNode.h"
class CurtainCall :public ISceneNode
{
private:
	Animation *m_pAni;
public:
	CurtainCall();
	~CurtainCall();

	void Update(float eTime);
	void Render();
};
