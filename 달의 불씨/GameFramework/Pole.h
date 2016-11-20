#pragma once

#include	"ISceneNode.h"
#include	"Physical.h"
#include	"Sprite.h"
#include	"CrashManager.h"
class Pole :virtual public ISceneNode, virtual public Physical
{
private:
	bool renderBool;
	Sprite *m_pPole;
	CrashManager *m_pCrash;

public:
	Pole();
	~Pole();

	int address;

	Pole*			GetInstance(){ return this; };

	void			Update(float eTime);
	void			Render();

	void			SetPos(int x, int y);
	void			SetAddress(int adr){ address = adr; };
	void			SetRenderBool(bool boolean){ renderBool = boolean; };
	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };

	D3DXVECTOR2		GetCenter(){ return m_pPole->GetCenterPosition(); };

	bool			GetRenderBool(){ return renderBool; };

};

