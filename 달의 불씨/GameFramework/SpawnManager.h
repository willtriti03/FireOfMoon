#pragma once
#include "ISceneNode.h"
#include "Touch.h"
#include "Stick.h"
#include "Philla.h"
#include "Npc.h"
#include "Fan.h"
#include "Pulley.h"
#include "Pole.h"
#include <list>
#include <iostream>
#include <fstream>
#define SpawnMgr SpawnManager::GetInstance()


using namespace std;
class Hyena;

class SpawnManager:public ISceneNode
{

public:
	SpawnManager();
	~SpawnManager();

	static SpawnManager* Instance;


	void Update(float eTime);
	void Render();

	struct RenderTouch
	{
		Touch *m_pTouch;
		bool  renderBool;
	};
	struct RenderNpc
	{
		Npc *m_pNpc;
		bool  renderBool;
	};
	struct RenderFan
	{
		Fan *m_pFan;
		bool  renderBool;
	};
	struct RenderStick
	{
		Stick *m_pStick;
		bool  renderBool;
	};
	struct RenderPhilla
	{
		Philla *m_pPhilla;
		bool  renderBool;
	};
	struct RenderPulley
	{
		Pulley *m_pPulley;
		bool renderBool;

	};
	struct RenderHyena
	{
		Hyena *m_pHyena;
		bool renderBool;
	};
	struct RenderPole
	{
		Pole *m_pPole;
		bool renderBool;
	};

	void PushTouch(Touch *touch, int max);
	void PushNpc(Npc *npc, int max);
	void PushFan(Fan *fan, int max);
	void PushStick(Stick *stick,  int max);
	void PushPhilla(Philla *philla, int max);
	void PushHyena(Hyena *hyena, int max);
	void PushPulley(Pulley *pulley, int max);
	void PushPole(Pole *pole, int max);

	void FflushList();
	void MoveMap(int move);
	void SetFirePhilla(int x, int y);
	void SetFirePhilla(D3DXVECTOR2 point);
	void SetLight(Light *light){ m_pLight = light; };

	void SwitchPoint(D3DXVECTOR2 pos);
	
	void CommitGlove(string statge);
	void CommitShakes(D3DXVECTOR2 mapPos,D3DXVECTOR2 charPos);

	bool ChageBool(Physical *phy,bool boolean);
	
	static SpawnManager* GetInstance();
	static void InstanceReset();

private:
	bool onetime = true;
	list<RenderTouch>	m_lTouch;
	list<RenderFan>		m_lFan;
	list<RenderStick>	m_lStick;
	list<RenderPhilla>	m_lPhilla;
	list<RenderNpc>		m_lNpc;
	list<RenderHyena>	m_lHyena;
	list<RenderPulley>	m_lPulley;
	list<RenderPole>	m_lPole;


	list<RenderTouch>::iterator iter;
	list<RenderNpc>::iterator iter2;
	list<RenderFan>::iterator iter3;
	list<RenderStick>::iterator iter4;
	list<RenderPhilla> ::iterator iter5;
	list<RenderHyena>::iterator iter6;
	list<RenderPulley> ::iterator iter7;
	list<RenderPole>::iterator iter8;

	Philla				*m_pFirePhllia;
	Light				*m_pLight;
};

