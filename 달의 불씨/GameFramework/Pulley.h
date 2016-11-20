#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "Physical.h"
#include "CrashManager.h"
class Pulley:virtual ISceneNode,virtual public Physical
{
private:
	bool renderBool;
	Sprite *m_pPulley;
	CrashManager *m_pCrash;
public:
	Pulley();
	~Pulley();

	Pulley *GetInstance(){ return this; };
	void Update(float eTime);
	void Render();


	void			SetPos(int x, int y);
	void			SetRenderBool(bool boolean){ renderBool = boolean; };
	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };

	bool			GetRenderBool(){ return renderBool; };

};

