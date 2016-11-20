#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "Physical.h"
#include "CrashManager.h"
#include "Character.h"
class SpawnManager;
class Hyena :virtual ISceneNode, virtual public Physical
{

private:
	bool renderBool;
	Sprite *m_pHyena;
	Character *m_pCharacter;
	CrashManager *m_pCrash;
	SpawnManager *m_pSwapn;
public:
	Hyena();
	~Hyena();

	Hyena *GetInstance(){ return this; };
	void Update(float eTime);
	void Render();


	void			SetPos(int x, int y);
	void			SetChar(Character *ch){ m_pCharacter = ch; };
	void			SetSpawn(SpawnManager *sw){ m_pSwapn = sw; };
	void			SetRenderBool(bool boolean){ renderBool = boolean; };
	void			SetCrashMgr(CrashManager *cm){ m_pCrash = cm; };

	bool			GetRenderBool(){ return renderBool; };
};

