#pragma once
#pragma warning
#include "InputManager.h"
#include "ISceneNode.h"
#include "SceneManager.h"
#include "GUIButton.h"
#include "StartScene.h"

class PopUp :public ISceneNode
{
private:

	GUIButton *m_pContinueBtn;
	GUIButton *m_pStopBtn;

	bool *check;

public:
	PopUp();
	~PopUp();

	void Update(float eTime);
	void Render();
	void SetBool(bool *boolean) { check = boolean; };
};

