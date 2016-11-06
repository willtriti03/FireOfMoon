#pragma once

#include "ISceneNode.h"
#include "Application.h"
#include "Physical.h"
#include "Character.h"
#include <list>
//#define CrushMgr CrashManager::GetInstance()

using namespace std;

class CrashManager
{
private:
	list<Physical*> phyList;
	list<int> centerList;
	Physical *arrayPhy[20];
	Character *m_pCharacter;


public:
	CrashManager();
	~CrashManager();
	

	void Update();

	void CheckStack(Physical *m_pPhy);
	void SetCharacter(Character *Character);
	void CleanStack(){ phyList.clear(); };
	Physical* CheckTest(int movement);
	
};

