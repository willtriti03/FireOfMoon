#pragma once

#include	"ISceneNode.h"
#include	"CrashManager.h"
#include   "Physical.h"
#include "CrashManager.h"

class Fan :virtual public ISceneNode, virtual public Physical
{
private:
	bool renderBool;

	Sprite *m_pFan;
	CrashManager *m_pCrash;
public:
	Fan();
	~Fan();
	void			Update(float eTime);
	void			Render();

	Fan*			GetInstance(){ return this; };

	void			SetPos(int x, int y);
	void			SetRenderBool(bool boolean){ renderBool = boolean; };
	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };

	bool			GetRenderBool(){ return renderBool; };

};

