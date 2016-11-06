#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "GUIButton.h"
#include "SceneManager.h"
#include "MainScene.h"
#include "Credit.h"
#include "CSound.h"
class StartScene :public ISceneNode
{
private:
	Sprite *m_pBackground;
	Sprite *m_pTitle;
	GUIButton *m_pStartBtn;
	GUIButton *m_pCreditBtn;
	GUIButton *m_pExitBtn;
	CSound	*m_pBgm;
public:
	StartScene();
	~StartScene();

	void Update(float eTime);
	void Render();
	void InstallFont();
};
