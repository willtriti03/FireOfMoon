#pragma once

#include	"ISceneNode.h"
#include   "Physical.h"
#include	"CrashManager.h"
#include	"Fire.h"
class Philla :virtual public ISceneNode, virtual public Physical
{
private:
	Fire *m_pFire;
	bool renderBool;
	bool fire=false;
	bool realPhilla=false;
	Sprite *m_pPhilla;
	CrashManager *m_pCrash;
public:
	Philla();
	~Philla();

	Philla*			GetInstance(){ return this; };
	
	void			Update(float eTime);
	void			Render();
	
	void			SetPos(int x, int y);
	void			SetRenderBool(bool boolean){ renderBool = boolean; };
	void			SetFire(bool boolean){ fire = boolean;};
	void			SetFirePosition();
	void			SetReal(bool boolean){ realPhilla = boolean; };
	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };

	void			GetFire(Fire *fire){ m_pFire = fire; };
	void			LostFire(){ m_pFire = NULL; };

	bool			GetFireBool(){ return fire; };
	bool			GetRenderBool(){ return renderBool; };
	bool			GetRealPhilla(){ return realPhilla; };


	D3DXVECTOR2		GetPhillaPosition(){ return m_pPhilla->GetPosition(); };
};

