#include "NextStageManager.h"
#include "DirectionC.h"
#include "DirectionE.h"
#include "DirectionD.h"
#include "DirectionH.h"
#include "DirectionB.h"
#include "ImageT.h"

NextStageManager::NextStageManager()
{
	pickGlove = 0;
	ct = new CurtainCall();
}


NextStageManager::~NextStageManager()
{
}

void NextStageManager::PickUpGlove() {
	pickGlove++;

}

void NextStageManager::UpgradeFire() {
	cnt++;
}

void NextStageManager::UpgradeFireOnce(string path) {
	if (cnt == 1) {
		ct = new CurtainCall;
		rd = true;
		time = TimeMgr->GetTime() + 4.5;
		nextStage = path;
		timer = true;
		cnt = 0;
	}
}

void NextStageManager::UpgradeFireTriple(string path) {
	if (cnt == 3) {
		ct = new CurtainCall;
		rd = true;
		time = TimeMgr->GetTime() + 4.5;
		nextStage = path;
		timer = true;
		cnt=0;
	}
}

void NextStageManager::UpgradeFireFourth(string path) {
	if (cnt == 4) {
		ct = new CurtainCall;
		rd = true;
		time = TimeMgr->GetTime() + 4.5;
		nextStage = path;
		timer = true;
		cnt=0;
	}
}
void NextStageManager::Render(){
	ISceneNode::Render();
	if (rd)
		ct->Render();
}
void NextStageManager::MetNPC(){
	npc++;
}
void NextStageManager::RealUse() {
	SceneMgr->changeScene(new DirectionH);
}

void NextStageManager::Update(float eTime){
	ISceneNode::Update(eTime);
	if (rd)
		ct->Update(eTime);
	CheckStage();
	if (timer){
		if (time<=TimeMgr->GetTime()){
			if (nextStage.compare("second") == 0){
				rd = false;
				SceneMgr->changeScene(new DirectionB);
			}		
			else if (nextStage.compare("third") == 0){
				rd = false;
				SceneMgr->changeScene(new DirectionC);

			}		 
			else if (nextStage.compare("fourth") == 0){
				rd = false;
				SceneMgr->changeScene(new MainScene("fourth"));
			}		 
			else if (nextStage.compare("five") == 0){
				rd = false;
				SceneMgr->changeScene(new DirectionE);
			}		 
			else if (nextStage.compare("six") == 0){
				rd = false;
				SceneMgr->changeScene(new DirectionD);
			}		 
			else if (nextStage.compare("seven") == 0){
				rd = false;
				SceneMgr->changeScene(new MainScene("seven"));
			}		 
			else if (nextStage.compare("eight") == 0){
				rd = false;
				SceneMgr->changeScene(new MainScene("eight"));
			}
			else if (nextStage.compare("nine") == 0){
				rd = false;
				SceneMgr->changeScene(new ImageT);
			}
			time = 0;
			timer = false;
		}
	}

}

void NextStageManager::CheckStage(){
	if (stage.compare("first")==0){
		if (pickGlove == 1){
			ct = new CurtainCall;
			rd = true;
			time = TimeMgr->GetTime()+1;
			nextStage = "second";
			timer = true;
			pickGlove = 0;
		}
	}
	else if (stage.compare("second") == 0){
		UpgradeFireOnce("third");
	}
	else if (stage.compare("third") == 0){
		UpgradeFireOnce("fourth");
	}
	else if (stage.compare("fourth") == 0){
		UpgradeFireTriple("six");
	}
	else if (stage.compare("five") == 0){
		UpgradeFireFourth("six");
	}
	else if (stage.compare("six") == 0){
		UpgradeFireTriple("seven");
	}
	else if (stage.compare("seven") == 0){		
		UpgradeFireTriple("eight");
	}
	else if (stage.compare("eight") == 0){
		if (npc == 1){
			ct = new CurtainCall;
			rd = true;
			time = TimeMgr->GetTime() + 1;
			nextStage = "nine";
			timer = true;
			npc = 0;
		}
	}
	

}