#pragma once
#define GageMgr Gagebar::GetInstance() 
#include "ISceneNode.h"
#include "Sprite.h"
#include "Timer.h"
#include "Animation.h"
class Gagebar:public ISceneNode
{
	float gageTime;
	float startTime;
	bool updateBool = false;
	bool renderBool = false;

	Animation *m_pGageBar;

public:
	Gagebar();
	~Gagebar();


	void SetGage(int time){ 
		gageTime = time;
		startTime = TimeMgr->GetTime();
		m_pGageBar->SetFrameSpeed(
			(float)m_pGageBar->GetMaxFrame() / time*2
		); 
		m_pGageBar->Restart(); };
	void Start(){ updateBool = true; renderBool = true; };

	void Update(float time);
	void Render();

	static Gagebar* GetInstance(){ static Gagebar Instance; return &Instance; };
};

