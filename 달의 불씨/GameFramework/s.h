#pragma once
#include "InputManager.h"
#include "ISceneNode.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "GUIButton.h"
#include "PrintFont.h"
#include "StartScene.h"

class MainScene;
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
