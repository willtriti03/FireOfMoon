#pragma once
#include "Sprite.h"
#include "ISceneNode.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "StartScene.h"


class Credit :public ISceneNode
{
private:
	Sprite *m_pCredit;
	Sprite *m_pBackground;
	Sprite *m_pOpacity;
public:
	Credit();
	~Credit();

	void Update(float eTime);
	void Render();
	void SetBGMiddle(Sprite *m_pCredit);
};
