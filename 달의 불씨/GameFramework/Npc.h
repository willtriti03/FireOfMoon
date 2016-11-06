#pragma once
#include	"ISceneNode.h"
#include	"Physical.h"
#include	"CrashManager.h"
#include	"Animation.h"

class Npc:virtual public ISceneNode, virtual public Physical
{
private:
	bool renderBool;
	bool renderSel;
	Sprite *m_pNpc;
	Animation *m_pAni;
	CrashManager *m_pCrash;
public:
	Npc();
	~Npc();
	
	Npc*			GetInstance(){ return this; };
	
	void			Update(float eTime);
	void			Render();

	void			RunAni();
	void			RenderSel(){ renderSel = !renderSel; };

	void			SetPos(int x, int y);
	void			SetRenderBool(bool boolean){ renderBool = boolean; };
	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };
	bool			GetRenderBool(){ return renderBool; };
};

