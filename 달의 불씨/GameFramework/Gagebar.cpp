#include "Gagebar.h"


Gagebar::Gagebar()
{

	m_pGageBar = new Animation();
	m_pGageBar->Create(8, 10, false);
	m_pGageBar->GenerateAnimation("resource/timer");
	m_pGageBar->SetPosition(487,650);
	startTime = TimeMgr->GetTime();
}


Gagebar::~Gagebar()
{
}
void Gagebar::Update(float  eTime){
	ISceneNode::Update(eTime);
	m_pGageBar->Update(eTime);
	//printf("%d %f\n", TimeMgr->GetTime(), TimeMgr->GetFrame());
	if (updateBool){
		float deltaTime = TimeMgr->GetTime() - startTime;
		float scaleX = (gageTime - deltaTime) / gageTime;
		if (scaleX <= 0){
			updateBool = false;
			renderBool = false;
		}
	}
}
void Gagebar::Render(){
	ISceneNode::Render();
	if (renderBool){
		m_pGageBar->Render();
	}
}