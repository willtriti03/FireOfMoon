#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "Physical.h"
#include "Animation.h"
#include "CrashManager.h"

class Touch :virtual public ISceneNode, virtual public Physical
{
private:
	bool renderBool;
	bool fire=false;
	Sprite *m_pTouch;
	CrashManager *m_pCrash;
public:
	Touch();
	~Touch();
	
	void			Update(float eTime);
	void			Render();

	void			TurnOn();
	void			TurnOff();
	void			SetPos(int x, int y);
	void			SetRenderBool(bool boolean){ renderBool = boolean; };

	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };
	Touch*			GetTouch(){ return this; };

	bool			FireState(){ return fire; };
	bool			GetRenderBool(){ return renderBool; };

};

