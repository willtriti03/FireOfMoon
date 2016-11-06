#pragma once
#include "ISceneNode.h"
#include "Animation.h"
#include "CurtainCall.h"
#include "SceneManager.h"
#include "MainScene.h"
#include "Timer.h"
#include <string>

using namespace std;
class DirectionI:public ISceneNode
{
private:
	CurtainCall *m_pCurtainCall;
	string stage;
	bool check = false;
	float time;
public:
	DirectionI(string path);
	~DirectionI();

	void Update(float eTime);
	void Render();
};

