#pragma once

#include	"ISceneNode.h"
#include	"Physical.h"
#include	"Sprite.h"
#include	"CrashManager.h"
class Stick :virtual public ISceneNode, virtual public Physical
{
private:
	bool renderBool;
	Sprite *m_pStrick;
	CrashManager *m_pCrash;

public:

	Stick();
	~Stick();
	
	Stick*			GetInstance(){ return this; };
	void			Update(float eTime);
	void			Render();

	void			SetPos(int x, int y);
	void			SetRenderBool(bool boolean){ renderBool = boolean; };
	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };

	bool			GetRenderBool(){ return renderBool; };

};

