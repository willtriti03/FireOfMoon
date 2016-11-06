#pragma once
#include "MainScene.h"
#include "SceneManager.h"
#include "Timer.h"
#include "CurtainCall.h"
#include "ISceneNode.h"
#define StageMgr NextStageManager::GetInstance()
class Fire;
class MainScene;
class NextStageManager:public ISceneNode
{
private:
	int cnt = 0;
	int npc = 0;
	int pickGlove=0;

	bool timer = false;
	bool rd = false;

	float time;
	CurtainCall *ct;
	string stage,nextStage;
public:
	NextStageManager();
	~NextStageManager();
	void Update(float eTime);
	void Render();

	void SetStage(string stage){ this->stage = stage; };
	void PickUpGlove();
	void UpgradeFire();
	void UpgradeFireOnce(string path);
	void UpgradeFireTriple(string path);
	void UpgradeFireFourth( string path);	
	void MetNPC();
	void RealUse();
	void CheckStage();


	static NextStageManager* GetInstance() {
		static NextStageManager Instance;
		return &Instance;
	}
};